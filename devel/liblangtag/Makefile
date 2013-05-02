# $FreeBSD$

PORTNAME=	liblangtag
PORTVERSION=	0.4.0
CATEGORIES=	devel textproc
MASTER_SITES=	https://cdn.bitbucket.org/tagoh/liblangtag/downloads/

MAINTAINER=	office@FreeBSD.org
COMMENT=	An interface library to access tags for identifying languages

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pathfix pkgconfig
CONFIGURE_ARGS=	--disable-introspection
USE_LDCONFIG=	yes

.include <bsd.port.mk>
