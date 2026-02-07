--- src/command_line.cpp.orig	2015-03-24 17:13:41 UTC
+++ src/command_line.cpp
@@ -118,7 +118,7 @@ CommandLine::parse (int argc, char** arg
 void
 CommandLine::print_help ()
 {
-  std::cout << "Construo "VERSION"\n\n"
+  std::cout << "Construo " VERSION "\n\n"
             << "Usage: construo [OPTIONS] [FILENAME]\n\n"
             << "  -h, --help                  display this help text\n"
             << "  -v,--version                Print version number of the programm\n"
@@ -135,7 +135,7 @@ CommandLine::print_help ()
 void
 CommandLine::print_version ()
 {
-  std::cout << "Construo "VERSION"\n"
+  std::cout << "Construo " VERSION "\n"
             << "Written by Ingo Ruhnke <grumbel@gmx.de>\n\n"
             << "Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>\n"
             << "This is free software; see the source for copying conditions.  There is NO\n"
