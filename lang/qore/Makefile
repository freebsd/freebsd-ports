# $FreeBSD$

PORTNAME=	qore
PORTVERSION=	0.8.12
CATEGORIES=	lang

MAINTAINER=	estrabd@gmail.com
COMMENT=	Qore Programming Language

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libmpfr.so:math/mpfr
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/bin/bison:devel/bison \
		${LOCALBASE}/bin/bash:shells/bash

BROKEN_armv6=		fails to compile: calling a private constructor of class 'ReferenceNode'
BROKEN_armv7=		fails to compile: calling a private constructor of class 'ReferenceNode'
BROKEN_powerpc=		fails to build
BROKEN_powerpc64=	fails to compile: unsupported relocation against r1

USES=	gmake iconv libtool:build pathfix autoreconf ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	qorelanguage

CONFIGURE_ENV=	LEX="${LOCALBASE}/bin/flex" PTHREAD_LIBS="-lpthread"
CONFIGURE_ARGS=	--disable-debug --disable-static --with-doxygen=no
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

pre-configure:
	cd ${WRKSRC}; ./reconf.sh

post-configure:
	${REINPLACE_CMD} -e 's|; make|; $${MAKE}|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
