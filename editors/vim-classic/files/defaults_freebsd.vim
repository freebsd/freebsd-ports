let g:is_posix = 1   " Our /bin/sh is POSIX, not bash

" Load a port template when creating a Makefile under the ports tree
augroup FreeBSD
    autocmd!
    autocmd BufNewFile /usr/ports/*/*/Makefile 0r /usr/ports/Templates/Makefile
    if !empty($PORTSDIR)
        autocmd BufNewFile $PORTSDIR/*/*/Makefile 0r $PORTSDIR/Templates/Makefile
    endif
augroup END
