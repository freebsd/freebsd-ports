PORTNAME=		fstrm
DISTVERSION=		0.6.1
CATEGORIES=		devel
MASTER_SITES=		https://dl.farsightsecurity.com/dist/${PORTNAME}/ \
			https://dns.company/downloads/${PORTNAME}/

MAINTAINER=		freebsd@dns.company
COMMENT=		Implementation of the Frame Streams data transport protocol in C

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libevent.so:devel/libevent

USES=			gmake libtool pkgconfig

GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=		DOXYGEN DOCS
DOXYGEN_DESC=		Use doxygen for docs
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

PORTDOCS=		*

.include <bsd.port.mk>
