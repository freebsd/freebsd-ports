PORTNAME=	libastylej
PORTVERSION=	3.6.19
CATEGORIES=	devel java textproc
PKGNAMESUFFIX?=	# for slave port

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code indenter, formatter, and beautifier (JNI library)
WWW=		https://astyle.sourceforge.net/

LICENSE=	LGPL3

USES=		compiler:c++11-lang gmake java

USE_GITLAB=	yes
GL_ACCOUNT=	saalen
GL_PROJECT=	astyle
USE_LDCONFIG=	yes

MAKE_ARGS+=	JAVA_HOME=${JAVA_HOME}
ALL_TARGET=	java

LDFLAGS+=	-s

WRKSRC_SUBDIR=	AStyle/build/${CHOSEN_COMPILER_TYPE}

PLIST_FILES=	lib/jni/libastylej${PKGNAMESUFFIX}.so \
		lib/jni/libastylej${PKGNAMESUFFIX}.so.${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's,\(JAVAINCS.*=.*\),\1 -I$(JAVA_HOME)/include/freebsd,' \
	-e 's,libastylej\.so,libastylej${PKGNAMESUFFIX}\.so,g' \
	-e 's/CXX = g++/CXX ?= g++/' \
	-e 's/--symbolic --force/-sf/' \
	-e 's/PATCHVER = 13/PATCHVER = '${PORTVERSION:E}'/' \
	${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/jni
	${INSTALL_DATA} ${WRKSRC}/bin/*.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/jni
	${LN} -sf libastylej${PKGNAMESUFFIX}.so.${PORTVERSION} \
	${STAGEDIR}${PREFIX}/lib/jni/libastylej${PKGNAMESUFFIX}.so

.include <bsd.port.mk>
