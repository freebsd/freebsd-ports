PORTNAME=	grig
DISTVERSION=	0.9.1
CATEGORIES=	comms hamradio
MASTER_SITES=	https://github.com/fillods/grig/releases/download/${PORTNAME:tu}-${DISTVERSION:S/./_/g}/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio control front-end
WWW=		https://groundstation.sourceforge.net/ \
		https://github.com/fillods/grig/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libhamlib.so:comms/hamlib \
		libharfbuzz.so:print/harfbuzz

USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk20 intltool

GNU_CONFIGURE=	yes

MAKE_ARGS+=	pkgdatadir=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
