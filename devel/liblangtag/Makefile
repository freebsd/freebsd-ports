# $FreeBSD$

PORTNAME=	liblangtag
PORTVERSION=	0.5.4
CATEGORIES=	devel textproc
MASTER_SITES=	https://bitbucket.org/tagoh/liblangtag/downloads/ \
		LOCAL/jkim

MAINTAINER=	office@FreeBSD.org
COMMENT=	Interface library to access tags for identifying languages

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize
USE_LDCONFIG=	yes
USES=		gmake iconv libtool pathfix pkgconfig tar:bzip2
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-introspection

.include <bsd.port.mk>
