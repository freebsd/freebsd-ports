# $FreeBSD$

PORTNAME=	liblangtag
PORTVERSION=	0.5.1
CATEGORIES=	devel textproc
MASTER_SITES=	https://cdn.bitbucket.org/tagoh/liblangtag/downloads/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim

MAINTAINER=	office@FreeBSD.org
COMMENT=	An interface library to access tags for identifying languages

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

CONFIGURE_ARGS=	--disable-introspection

.include <bsd.port.mk>
