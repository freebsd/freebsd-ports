PORTNAME=	liblangtag
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	https://bitbucket.org/tagoh/liblangtag/downloads/ \
		LOCAL/jkim

MAINTAINER=	office@FreeBSD.org
COMMENT=	Interface library to access tags for identifying languages
WWW=		https://bitbucket.org/tagoh/liblangtag/wiki/Home

LICENSE=	LGPL3 MPL20
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		iconv gnome libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	libxml2
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-introspection

.include <bsd.port.mk>
