# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=		fstrm
PORTVERSION=		0.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=		devel

MAINTAINER=		freebsd@dns-lab.com
COMMENT=		Implementation of the Frame Streams data transport protocol in C

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libevent.so:${PORTSDIR}/devel/libevent2

USE_GITHUB=		yes
GH_ACCOUNT=		farsightsec

GNU_CONFIGURE=		yes
USE_AUTOTOOLS=		automake autoconf:env libtoolize
USE_LDCONFIG=		yes
USES=			libtool gmake pkgconfig

OPTIONS_DEFINE=		DOXYGEN
DOXYGEN_DESC=		Use doxygen for docs
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

PORTDOCS=		*

run-autotools:
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh

.include <bsd.port.mk>
