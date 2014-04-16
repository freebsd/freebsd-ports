# $FreeBSD$

PORTNAME=	liblangtag
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	https://cdn.bitbucket.org/tagoh/liblangtag/downloads/ \
		LOCAL/jkim

MAINTAINER=	office@FreeBSD.org
COMMENT=	Interface library to access tags for identifying languages

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gmake iconv:build pathfix pkgconfig

CONFIGURE_ARGS=	--disable-introspection

.include <bsd.port.mk>
