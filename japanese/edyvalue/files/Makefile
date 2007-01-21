# $FreeBSD$

PROG=		EdyValue
DPADD=		${LOCALBASE}/lib/libpasori.a
LDADD=		-L${LOCALBASE}/lib -lpasori

BINDIR=		${LOCALBASE}/bin
NO_MAN=

CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-Wall -W

.include <bsd.prog.mk>
