#--------------------------------
# jhead makefile for FreeBSD
# $FreeBSD$
#--------------------------------

OBJ=.
SRC=.

all: jhead

objs = $(OBJ)/jhead.o $(OBJ)/exif.o

$(OBJ)/%.o:$(SRC)/%.c
	cc ${CFLAGS} -Wall -c $< -o $@

jhead: $(objs) jhead.h
	cc -o jhead $(objs) -lm
