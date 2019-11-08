# $FreeBSD$

PORTNAME=	diff-pdf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-20190713
CATEGORIES=	graphics

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Tool for visually comparing two PDFs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libpoppler-glib.so:graphics/poppler-glib

USES=		autoreconf compiler:c++11-lang gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vslavik
GH_TAGNAME=	6741ab9
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
USE_GNOME=	cairo glib20
USE_WX=		2.8+

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/AM_PATH_WXCONFIG/ s,3.0.0,2.8.0,' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
