# $FreeBSD$

CFLAGS+=-fno-builtin -nostdinc -I. -Wall -Werror
LDFLAGS+=-nostdlib -Wl,-N -Wl,-Ttext -Wl,100000

PROG=	invaders
OBJS=	boot.o common.o kernel.o keyboard.o video.o game.o sound.o \
	delay.o memory.o

all: ${PROG}

${PROG}: ${PROG}.exec
	objcopy -O binary invaders.exec invaders

${PROG}.exec: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG}.exec ${OBJS}

clean:
	rm -f ${OBJS} ${PROG}

