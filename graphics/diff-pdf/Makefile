# $FreeBSD$

PORTNAME=	diff-pdf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2-27
DISTVERSIONSUFFIX=	-gc4d6722
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Tool for visually comparing two PDFs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libpoppler-glib.so:graphics/poppler-glib

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vslavik
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
USE_GNOME=	cairo glib20
USE_WX=		2.8+

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/AM_PATH_WXCONFIG/ s,3.0.0,2.8.0,' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
