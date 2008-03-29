# Makefile
# $FreeBSD$

CC?= cc
CFLAGS?= -O2 -Wall
CCFLAGS+= $(CFLAGS) -shared -fPIC -DPIC
LDFLAGS+= -export-dynamic -shared
LIBS?=

all:
	$(CC) $(CCFLAGS) -c SHA-256.c
	$(CC) $(CCFLAGS) -c base64.c
	$(CC) $(CCFLAGS) -c blowfish.c
	$(CC) $(CCFLAGS) -c cfgopts.c
	$(CC) $(CCFLAGS) -c DH1080.c
	$(CC) $(CCFLAGS) -c FiSH.c
	$(CC) $(LDFLAGS) -o xfish.so FiSH.o SHA-256.o base64.o blowfish.o cfgopts.o DH1080.o -lmiracl ${LIBS}

