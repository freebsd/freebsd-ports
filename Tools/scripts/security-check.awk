BEGIN {
	file = "";
	if (audit != "")
		stupid_functions_regexp="^(gets|mktemp|tempnam|tmpnam|strcpy|strcat|sprintf)$";
	else
		stupid_functions_regexp="^(gets|mktemp|tempnam|tmpnam)$";
	split("", stupid_binaries);
	split("", network_binaries);
	split("", setuid_binaries);
	split("", writable_files);
	split("", startup_scripts);
	header_printed = 0;
}
FILENAME ~ /\.flattened$/ {
	if ($0 ~ /(^|\/)etc\/rc\.d\//)
		startup_scripts[$0] = 1;
}
FILENAME ~ /\.objdump$/ {
	if (match($0, /: +file format [^ ]+$/)) {
		file = substr($0, 1, RSTART - 1);
		stupid_functions = "";
		next;
	}
	if (file == "")
		next;
	if ($3 ~ /^(gets|mktemp|tempnam|tmpnam)$/ ||
	  ($3 ~ /^(strcpy|strcat|sprintf)$/ && audit != ""))
		stupid_binaries[file] = stupid_binaries[file] " " $3;
	if ($3 ~ /^(accept|recvfrom)$/)
		network_binaries[file] = 1;
}
FILENAME ~ /\.setuid$/ { setuid_binaries[$0] = 1; }
FILENAME ~ /\.writable$/ { writable_files[$0] = 1; }
function print_header() {
	if (header_printed)
		return;
	if (audit != "")
		print "===> SECURITY REPORT (PARANOID MODE): ";
	else
		print "===> SECURITY REPORT: ";
	header_printed = 1;
}
function note_for_the_stupid(file) { return (file in stupid_binaries) ? (" (USES POSSIBLY INSECURE FUNCTIONS:" stupid_binaries[file] ")") : ""; }
END {
	note_printed = 0;
	for (file in setuid_binaries) {
		if (!note_printed) {
			print_header();
			print "      This port has installed the following binaries which execute with";
			print "      increased privileges.";
			note_printed = 1;
		}
		print file note_for_the_stupid(file);
	}
	if (note_printed)
		print "";
	note_printed = 0;
	for (file in network_binaries) {
		if (!note_printed) {
			print_header();
			print "      This port has installed the following files which may act as network";
			print "      servers and may therefore pose a remote security risk to the system.";
			note_printed = 1;
		}
		print file note_for_the_stupid(file);
	}
	if (note_printed) {
		print "";
		note_printed = 0;
		for (file in startup_scripts) {
			if (!note_printed) {
				print_header();
				print "      This port has installed the following startup scripts which may cause";
				print "      these network services to be started at boot time.";
				note_printed = 1;
			}
			print file;
		}
		if (note_printed)
			print "";
	}
	note_printed = 0;
	for (file in writable_files) {
		if (!note_printed) {
			print_header();
			print "      This port has installed the following world-writable files/directories.";
			note_printed = 1;
		}
		print file;
	}
	if (note_printed)
		print "";
	if (header_printed) {
		print "      If there are vulnerabilities in these programs there may be a security";
		print "      risk to the system. FreeBSD makes no guarantee about the security of";
		print "      ports included in the Ports Collection. Please type 'make deinstall'";
		print "      to deinstall the port if this is a concern.";
	}
	exit header_printed;
}
