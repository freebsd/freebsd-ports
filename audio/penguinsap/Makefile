# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	penguinsap
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line Atari(TM) .sap player

USE_DOS2UNIX=	yes

SOURCES=	sapPokey pokey1 sapCpu sapEngine main pokey0

.if defined(WITH_OPTIMIZED_CFLAGS)
EXTRAFLAGS=	-ffast-math -malign-double -finline-limit-1000000 \
		-funroll-loops -fstrength-reduce -finline-functions
.endif

PLIST_FILES=	bin/sap

.include <bsd.port.pre.mk>

_CLANG!=	${CXX} --version | ${HEAD} -1 | ${SED} -e 's/.*clang version \([0-9]\)\.\([0-9]\).*/\1\2/'
ISCLANG=	${_CLANG:M[34][0-9]}

# clang can build this without -fno-exceptions
.if empty(ISCLANG)
CXXFLAGS+=	-fno-exceptions
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
