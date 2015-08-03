\ Copyright (c) 2015 Devin Teske <dteske@FreeBSD.org>
\ All rights reserved.
\ 
\ Redistribution and use in source and binary forms, with or without
\ modification, are permitted provided that the following conditions
\ are met:
\ 1. Redistributions of source code must retain the above copyright
\    notice, this list of conditions and the following disclaimer.
\ 2. Redistributions in binary form must reproduce the above copyright
\    notice, this list of conditions and the following disclaimer in the
\    documentation and/or other materials provided with the distribution.
\ 
\ THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
\ ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
\ IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
\ ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
\ FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
\ DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
\ OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
\ HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
\ LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
\ OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
\ SUCH DAMAGE.
\ 
\ $FreeBSD$

create xenkerndefault 64 allot
0 xenkerndefault c!

also menu-command-helpers
also menu-namespace

: init_xen_active ( N -- N )
	s" [X]en Kernel.. off"                2 pick menu_caption[x] setenv
	s" [X]en Kernel.. On"                 2 pick toggled_text[x] setenv
	s" toggle_xen"                        2 pick menu_command[x] setenv
	s" 120"                               2 pick menu_keycode[x] setenv
	s" ^[1mX^[men Kernel.. ^[34;1mOff^[m" 2 pick ansi_caption[x] setenv
	s" ^[1mX^[men Kernel.. ^[32;7mOn^[m"  2 pick toggled_ansi[x] setenv
;

: init_xen_inactive ( N -- N )
	s" Xen Kernel.. N/A" 2dup
	4 pick menu_caption[x] setenv
	2 pick ansi_caption[x] setenv
	s" true" 2 pick menu_command[x] setenv
;

: init_xen ( -- )
	s" optionsmenu_options" getenv 0> if
		c@ dup [char] 0 > over [char] 9 < and false = if
			drop [char] 0
		then
		1+
	else
		[char] 1
	then
	begin
		dup [char] 8 > if
			false ( break )
		else
			dup s" optionsmenu_caption[x]" 20 +c! getenv -1 = if
				false ( break )
			else
				drop true
			then
		then
	while
		1+
	repeat

	s" xen_kernel" getenv dup -1 <> over 0> and if
		xenkerndefault 1+ 0 2swap strcat swap 1- c!
		init_xen_active ( n -- n )
		toggle_menuitem ( n -- n )
	else
		drop
		xenkerndefault c@ 0<> if
			init_xen_active ( n -- n )
		else
			init_xen_inactive ( n -- n )
		then
	then
;

: toggle_xen ( N -- N TRUE )
        toggle_menuitem ( n -- n )
        menu-redraw

	dup toggle_stateN @ 0= if
		s" xen_kernel" unsetenv
	else
		xenkerndefault count s" xen_kernel" setenv
	then

	TRUE \ loop menu again
;

set optionsmenu_init="$optionsmenu_init init_xen"
