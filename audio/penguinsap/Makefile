# New ports collection makefile for:	penguinsap
# Date created:				16 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	penguinsap
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line Atari(TM) .sap player

USE_DOS2UNIX=	yes

MAKE_JOBS_SAFE=	yes

SOURCES=	sapPokey pokey1 sapCpu sapEngine main pokey0

.if defined(WITH_OPTIMIZED_CFLAGS)
EXTRAFLAGS=	-ffast-math -malign-double -finline-limit-1000000 \
		-funroll-loops -fstrength-reduce -finline-functions
.endif

PLIST_FILES=	bin/sap

.include <bsd.port.pre.mk>

.if ${CXX:T} != "clang++"
CXXFLAGS+=	--no-exceptions
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard\.h|sys/soundcard\.h|' \
		${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's|--no-exceptions||' ${WRKSRC}/build.inc

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

.include <bsd.port.post.mk>
