#--------------------------------
# jhead makefile for FreeBSD
# $FreeBSD$
#--------------------------------

OBJ=.
SRC=.

all: jhead

objs = $(OBJ)/jhead.o $(OBJ)/jpgfile.o $(OBJ)/exif.o

$(OBJ)/%.o:$(SRC)/%.c
	${CC} ${CFLAGS} -Wall -c $< -o $@

jhead: $(objs) jhead.h
	${CC} -o jhead $(objs) -lm
