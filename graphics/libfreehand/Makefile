# $FreeBSD$

PORTNAME=	libfreehand
PORTVERSION=	0.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret and import Adobe/Macromedia drawings

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	librevenge-0.0.so:${PORTSDIR}/textproc/librevenge

GNU_CONFIGURE=	yes
USES=	libtool pathfix pkgconfig tar:xz
USE_LDCOFNIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs
PORTDOCS=	*

.include <bsd.port.mk>

