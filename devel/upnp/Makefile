# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	upnp
PORTVERSION=	1.6.25
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/p${PORTNAME}/p${PORTNAME}/libUPnP%20${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Universal Plug and Play Software Development Kit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

PORTSCOUT=	skipv:1.8.3	# released on 2017-11-14; older than 1.6.25

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
CPE_VENDOR=	libupnp_project
CPE_PRODUCT=	libupnp

PORTDOCS=	ixml/*.html upnp/*.html

OPTIONS_DEFINE=	DEBUG DOCS IPV6
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug
DOCS_CONFIGURE_WITH=	documentation=${DOCSDIR}
IPV6_CONFIGURE_ENABLE=	ipv6

pre-configure:
	${REINPLACE_CMD} -e '386s,docs/dist,,' ${WRKSRC}/Makefile.in

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/dist/html && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	${RM} -r ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
