#!/usr/local/bin/tclsh8.2

# Copyright (C) 2002 Daniel O'Connor.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the project nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

#
# Usage
#
# Ktrace the process(es) you're interested in like so ->
#
# ktrace -ditcn -f ~/install.ktr make install
#
# Now run kdump over this file and pipe to parse-kdump.tcl
# kdump -m1 -f ~/install.ktr | parse-kdump.tcl
#

proc main {} {
    set fh stdin;
    set state "CALL";
    set interested "";
    set cwd [pwd];
    set namea "";

    while {![eof $fh]} {
	gets $fh line;

	if {$line == ""} {
	    continue;
	}

	if {[scan $line "%d %s %s %\[^\n\]" pid name type rest] != 4} {
	    if {$state != "GIO"} {
		puts stderr "Unable to parse '$line'";
		exit 1;
	    } else {
		#puts stderr "Got IO";
		continue;
	    }
	}

	#puts stderr "Pid - $pid, Name - $name, Type - $type, Rest - $rest";

	switch -- $type {
	    "CALL" -
	    "RET" -
	    "GIO" -
	    "NAMI" {
	    }

	    default {
		puts stderr "Unknown type $type"
		exit 1;
	    }
	}

	#puts "State is $state";
	switch -- $type {
	    "CALL" {
		set namea "";
		if {$state != "RET" && $state != "CALL" && $state != "NAMI"} {
		    puts stderr "Invalid state transition from $state to CALL";
		    exit 1;
		} else {
		    set state $type;
		}

		set cargs "";
		set res [scan $rest "%\[^(\](%\[^)\]" callname cargs];
		if {$res != 1 && $res != 2} {
		    puts stderr "Couldn't derive syscall name from $rest";
		    exit 1;
		}

		if {$callname == "open"} {
		    if {[scan $cargs "%\[^,\],%\[^,\],%s" fptr flags mode] != 3} {
			puts stderr "Couldn't parse open args from $cargs";
			exit 1;
		    }

		    #puts stderr "Open with $flags, mode $mode";
		    set interested [list $callname $flags $mode];
		} elseif {$callname == "chdir"} {
		    set interested [list $callname];
		} elseif {$callname == "rename"} {
		    set interested [list $callname];
		} elseif {$callname == "unlink"} {
		    set interested [list $callname];
		}
	    }

	    "RET" {
		set namea "";
		if {$state != "CALL" && $state != "GIO" && $state != "NAMI" && $state != "RET"} {
		    puts "Invalid state transition from $state to RET";
		    exit 1;
		} else {
		    set state $type;
		}
		set interested "";
	    }

	    "NAMI" {
		if {$state != "CALL" && $state != "NAMI"} {
		    puts "Invalid state transition from $state to NAMI";
		    exit 1;
		} else {
		    set state $type;
		}
		if {$interested != ""} {
		    if {[scan $rest "\"%\[^\"\]\"" fname] != 1} {
			puts stderr "Unable to derive filename from $rest";
			exit 1;
		    }

		    switch -- [lindex $interested 0] {
			"open" {
			    set flags [expr [lindex $interested 1]];
			    set mode [expr [lindex $interested 2]];
			    #puts stderr "Mode = $mode, Flags = $flags";
			    if {[file pathtype $fname] == "relative"} {
				set fname [file join $cwd $fname];
			    }
			    if {[expr $flags & 0x02] || [expr $flags & 0x200]} {
				#puts "Got an open for writing on $fname";
				#puts "$name $fname";
				puts "+$fname";
			    }
			}

			"rename" {
			    if {$namea != ""} {
				#puts "rename from $namea to $fname";
				puts "-$namea";
				puts "+$fname";
			    } else {
				set namea $fname;
				#puts "namea = $namea";
			    }
			}

			"chdir" {
			    set cwd "$fname";
			    #puts "Changed working directory to $cwd";
			}
			
			"unlink" {
			    puts "-$fname";
			}

			default {
			    puts "Got a [lindex $interested 0] $fname";
			}
		    }
		}
	    }

	    "GIO" {	
		set namea "";
		if {$state != "CALL" && $state != "GIO"} {
		    puts "Invalid state transition from $state to GIO";
		    exit 1;
		} else {
		    set state $type;
		}
	    }

	    default {
		puts stderr "WTF, Invalid state?"
		exit 1;
	    }
	}
    }
}

main;
