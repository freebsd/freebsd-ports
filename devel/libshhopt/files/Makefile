# $FreeBSD$

PREFIX	= /usr/local
LIBDIR	= $(PREFIX)/lib
INCSDIR	= $(PREFIX)/include
INCDIR	= $(INCSDIR)		# for 4.x bsd.lib.mk

example:
	$(CC) -o example example.c -I$(INCDIR) -L$(LIBDIR) -lshhopt
