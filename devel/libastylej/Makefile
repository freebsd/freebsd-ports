# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libastylej
PORTVERSION=	2.05.1
CATEGORIES=	devel java textproc
ASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	astyle_${PORTVERSION}_linux

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Source code indenter, formatter, and beautifier (JNI library)

LICENSE=	LGPL3

ALL_TARGET=	java
LDFLAGS+=	-s
USES=		compiler gmake
USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_ARGS+=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/astyle/build/${COMPILER_TYPE}

PLIST_FILES=	lib/jni/libastylej.so lib/jni/libastyle-${PORTVERSION}j.so

post-patch:
	@${REINPLACE_CMD} -e 's,\(JAVAINCS.*=.*\),\1 -I$(JAVA_HOME)/include/freebsd,' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/jni
	${INSTALL_DATA} ${WRKSRC}/bin/*.so ${STAGEDIR}${PREFIX}/lib/jni
	${LN} -sf libastyle-${PORTVERSION}j.so \
		${STAGEDIR}${PREFIX}/lib/jni/libastylej.so

.include <bsd.port.mk>
