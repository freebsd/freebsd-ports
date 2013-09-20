# Created by: David Romano <unobe@cpan.org>
# $FreeBSD$

PORTNAME=	libparserutils
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.netsurf-browser.org/projects/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	unobe@cpan.org
COMMENT=	Library useful when writing parsers (formerly a part of NetSurf)

USES=		gmake

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	ICONV STATIC TEST DOXYGEN
OPTIONS_DEFAULT=	ICONV STATIC TEST DOXYGEN

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
CFLAGS+=	-DWITH_ICONV_FILTER
LDFLAGS+=	${ICONV_LIB}
.endif

.if ${PORT_OPTIONS:MSTATIC}
PLIST_SUB+=	NO_STATIC="@comment " STATIC=""
.else
USES+=		perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
COMPONENT_TYPE=	lib-shared
MAKE_ENV+=	COMPONENT_TYPE=${COMPONENT_TYPE}
PLIST_SUB+=	NO_STATIC="" STATIC="@comment "
.endif

.if ${PORT_OPTIONS:MTEST}
USES+=		perl5
USE_PERL5=	build
ALL_TARGET+=	test
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
DOXYGEN_PORTDIR=${PORTSDIR}/devel/doxygen
BUILD_DEPENDS+=	doxygen:${DOXYGEN_PORTDIR}:build
PATH:=${PATH}:`cd ${DOXYGEN_PORTDIR}; make -V WRKSRC`/bin
ALL_TARGET+=	docs
MAKE_ENV+=	PATH=${PATH}
.endif

.include <bsd.port.mk>
