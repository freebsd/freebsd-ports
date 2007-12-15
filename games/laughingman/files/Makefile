# $FreeBSD$

PROG_CXX=	laugh
SRCS=		laugh.cpp
NO_MAN=		yes
LDADD=		-L${LOCALBASE}/lib -lcv -lcxcore -lhighgui

LOCALBASE?=	/usr/local
PREFIX?=	${LOCALBASE}
BINDIR?=	${PREFIX}/bin
DATADIR?=	${PREFIX}/share/laughingman

CXXFLAGS+=	-DDATADIR=\"${DATADIR}\" -I${LOCALBASE}/include -I${LOCALBASE}/include/opencv

FILES=		haarcascade_frontalface_alt.xml laughingman.bmp
FILESDIR=	${DATADIR}

MKDIR?=		mkdir -p

beforeinstall:
	${MKDIR} ${FILESDIR}

.include <bsd.prog.mk>
