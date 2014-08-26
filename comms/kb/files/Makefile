# Makefile for:		kb
#
# $FreeBSD$

LIBS+=  `pkg-config --cflags --libs gtk+-2.0`
LIBS+=  `pkg-config --cflags --libs libgnome-2.0`
LIBS+=  `pkg-config --cflags --libs bonobo-activation-2.0`

all:	kb kb_server

kb_server:	kb_server.c
	${CC} ${CFLAGS} -o kb_server kb_server.c -lm

kb:	boxes.c fboxes.c kb.c radio.c bsd_bells.c fields.c sboxes.c \
	couzon.c init.c kb_server.c support.c elogs.c io.c network.c tree.c
	${CC} ${CFLAGS} -DSPKR -I. ${LIBS} kb.c -o kb -lm
