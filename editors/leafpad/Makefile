PORTNAME=	leafpad
PORTVERSION=	0.8.19
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	SAVANNAH

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	GTK based simple text editor
WWW=		http://tarot.freeshell.org/leafpad/

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gettext gmake gnome localbase:ldflags \
		pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20 intlhack
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-chooser
LDFLAGS+=	-lpthread

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CHMOD} a+x ${WRKSRC}/install-sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
