# New ports collection makefile for:	penguinsap
# Date created:				16 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	penguinsap
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command line Atari(TM) .sap player

USE_REINPLACE=	yes

SOURCES=	sapPokey pokey1 sapCpu sapEngine main pokey0
CXXFLAGS+=	--no-exceptions

.if defined(WITH_OPTIMIZED_CFLAGS)
EXTRAFLAGS=	-ffast-math -malign-double -finline-limit-1000000 \
		-funroll-loops -fstrength-reduce -finline-functions
.endif

PLIST_FILES=	bin/sap

post-patch:
# gcc 2.95.4 does not like CR/LFs
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E -e 's|||' {} \;
	@${REINPLACE_CMD} -e 's|linux/soundcard\.h|sys/soundcard\.h|' \
		${WRKSRC}/main.cpp

do-build:
.for f in ${SOURCES}
	${CXX} ${CXXFLAGS} ${EXTRAFLAGS} -c ${WRKSRC}/${f}.cpp \
		-o ${WRKSRC}/${f}.o
.endfor
	${CC} ${CFLAGS} ${EXTRAFLAGS} ${SOURCES:C/(.*)/${WRKSRC}\/\1.o/} \
		-o ${WRKSRC}/sap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sap ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
