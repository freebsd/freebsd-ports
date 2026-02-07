lappend auto_path ..

foreach t [glob *.tcl] {
	puts "Running tests from $t"
	source $t
}
