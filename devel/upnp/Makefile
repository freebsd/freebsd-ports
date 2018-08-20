# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	upnp
PORTVERSION=	1.6.25
CATEGORIES=	devel
MASTER_SITES=	SF/p${PORTNAME}/p${PORTNAME}/libUPnP%20${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		cpe libtool pathfix tar:bzip2
CPE_VENDOR=	libupnp_project
CPE_PRODUCT=	libupnp
USE_LDCONFIG=	yes

PORTDOCS=	ixml/*.html upnp/*.html

OPTIONS_DEFINE=	DEBUG DOCS IPV6
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--enable-debug
DOCS_CONFIGURE_ON=	--with-documentation=${DOCSDIR}
DOCS_CONFIGURE_OFF=	--without-documentation
IPV6_CONFIGURE_ON=	--enable-ipv6

pre-configure:
	${REINPLACE_CMD} -e '386s,docs/dist,,' ${WRKSRC}/Makefile.in

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/dist/html && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	${RM} -r ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
