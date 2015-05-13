also menu-command-helpers

: boot_xen_disabled ( N -- NOTREACHED )
        toggle_menuitem ( n -- n )
        menu-redraw
        500 ms
        0 25 at-xy
        s" xen_kernel" getenv dup -1 <> if
	  1 1 unload
          s" xen_kernel" unsetenv
	else
	  drop
	  0  
	then
        0 boot ( state -- )
;

set mainmenu_caption[7]="Disable [X]en"
set maintoggled_text[7]="Disabling [X]en..."
set mainansi_caption[7]="Disable ^[1mX^[men"
set maintoggled_ansi[7]="Disabling ^[1mX^[men..."
set mainmenu_keycode[7]=120
set mainmenu_command[7]="boot_xen_disabled"

