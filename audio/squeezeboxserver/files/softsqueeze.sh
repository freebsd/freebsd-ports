#!/bin/sh
# This script requires that that java/javavmwrapper port and a JDK
# version 1.4 or greater be installed.
#
# The javavmwrapper port is not installed by default lest the JDK
# requirement drag this port down into oblivion.  Perhaps someday Sun
# will release the JDK under a license that makes dependencies on the
# JDK reasionable.
#
%%LOCALBASE%%/bin/javavm -jar /usr/local/slimserver/HTML/EN/html/softsqueeze/SoftSqueeze.jar
