# $FreeBSD$

CC        ?= gcc
CFLAGS    ?= -g -O2 -Wall
XROOT     = ${LOCALBASE}
LROOT	  = ${LOCALBASE}
INCLUDES  = -I$(XROOT)/include -I$(LROOT)/include
LIBS      = -lX11 -lXext -ljpeg -lpng -ltiff -lz -lungif -lm -lImlib
LDPATH    = -L$(XROOT)/lib -L$(LROOT)/lib

PROG      = show
PREFIX    = ${LOCALBASE}

all: $(PROG)

$(PROG): $(PROG).c
	$(CC) $(PROG).c $(CFLAGS) $(INCLUDES) $(LDPATH) $(LIBS) -o $(PROG)
