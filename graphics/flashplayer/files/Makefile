# $FreeBSD$

PROG=		swfplayer
SRCS=		main.c
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDADD=		-L${LOCALBASE}/lib -lflash -L${X11BASE}/lib -lX11 -lXext -lm
NOMAN=		YES
BINDIR=		${LOCALBASE}/bin

.include <bsd.prog.mk>
