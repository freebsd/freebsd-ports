# $FreeBSD$

PORTNAME=	qore
PORTVERSION=	0.8.12
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	estrabd@gmail.com
COMMENT=	Qore Programming Language

LICENSE=	MIT

BROKEN=		fails to compile: calling a private constructor of class 'ReferenceNode'
BROKEN_mips=		fails to link: single-compilation-unit.cpp:(.text+0xdfc): relocation truncated to fit: R_MIPS_CALL16 against '__ltdf2@@FBSDprivate_1.0'
BROKEN_mips64=		fails to link: single-compilation-unit.cpp:(.text+0xdfc): relocation truncated to fit: R_MIPS_CALL16 against '__ltdf2@@FBSDprivate_1.0'
BROKEN_powerpc=		fails to build
BROKEN_powerpc64=	fails to compile: unsupported relocation against r1

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libmpfr.so:math/mpfr
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/bin/bison:devel/bison \
		${LOCALBASE}/bin/bash:shells/bash

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
