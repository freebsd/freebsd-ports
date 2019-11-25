# $FreeBSD$

PROG=		SuicaValue
DPADD=		${LOCALBASE}/lib/libpasori.a
LDADD=		-L${LOCALBASE}/lib -lpasori

BINDIR=		${PREFIX}/bin
MAN=

CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-Wall -W

.include <bsd.prog.mk>
