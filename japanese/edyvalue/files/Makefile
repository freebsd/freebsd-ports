# $FreeBSD$

PROG=		EdyValue
DPADD=		${LOCALBASE}/lib/libpasori.a
LDADD=		-L${LOCALBASE}/lib -lpasori

BINDIR=		${LOCALBASE}/bin
MAN=

CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-Wall -W

.include <bsd.prog.mk>
