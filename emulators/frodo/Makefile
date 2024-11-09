PORTNAME=	frodo
PORTVERSION=	4.4
PORTREVISION=	0
CATEGORIES=	emulators tk
MASTER_SITES=	http://frodo.cebix.net/downloads/
DISTNAME=	Frodo-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulates a Commodore 64
WWW=		https://frodo.cebix.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg pkgconfig sdl gnome desktop-file-utils
USE_XORG=	x11 xt xext sm ice
USE_SDL=	sdl2
USE_GNOME=	gtk30 pango cairo gdkpixbuf2 glib20
GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/Frodo
DOCSDIR=	${PREFIX}/share/doc/Frodo

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_DEFAULT=

NLS_USES=	gettext-runtime

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}/
	${TAR} -C ${INSTALL_WRKSRC}/Docs -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -

.include <bsd.port.mk>
