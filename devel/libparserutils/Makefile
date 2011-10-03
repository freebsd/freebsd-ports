# ports collection makefile for:	libparserutils
# Date created:				20 August 2011
# Whom:					David Romano <unobe@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	libparserutils
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.rurs.us/fbsd/ports/

MAINTAINER=	unobe@cpan.org
COMMENT=	A library useful when writing parsers (formerly a part of NetSurf)

USE_GMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	ICONV	"Adds iconv support"			On \
		STATIC	"Build statically linked library"	On \
		TEST	"Enable tests"				On \
		DOXYGEN	"Build Doxygen Documentation"		On

.include <bsd.port.pre.mk>

.if defined(WITH_ICONV)
CFLAGS+=	-DWITH_ICONV_FILTER
LDFLAGS+=	-liconv
.endif

.if !defined(WITH_STATIC)
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
COMPONENT_TYPE=	lib-shared
MAKE_ENV+=	COMPONENT_TYPE=${COMPONENT_TYPE}
PLIST_SUB+=	NO_STATIC="" STATIC="@comment "
.else
PLIST_SUB+=	NO_STATIC="@comment " STATIC=""
.endif

.if defined(WITH_TEST)
USE_PERL5_BUILD=yes
ALL_TARGET+=	test
.endif

.if defined(WITH_DOXYGEN)
DOXYGEN_PORTDIR=${PORTSDIR}/devel/doxygen
BUILD_DEPENDS+=	doxygen:${DOXYGEN_PORTDIR}:build
PATH:=${PATH}:`cd ${DOXYGEN_PORTDIR}; make -V WRKSRC`/bin
ALL_TARGET+=	docs
MAKE_ENV+=	PATH=${PATH}
.endif

.include <bsd.port.post.mk>
