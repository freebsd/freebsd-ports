# Created by: Andrey Zakhvatov
# $FreeBSD$
#    $MCom: ports/biology/gperiodic/Makefile,v 1.1 2006/09/29 23:42:13 ahze Exp $

PORTNAME=	gperiodic
PORTVERSION=	3.0.3
CATEGORIES=	biology
MASTER_SITES=	https://sourceforge.net/projects/gperiodic/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a periodic table of the elements

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig\
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20

PORTDOCS=	AUTHORS ChangeLog README

LANGS=		be cs da de es fi fr gl is it ms pl pt ru sv tr uk zh_CN

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} `pkg-config --cflags --libs gtk+-2.0` \
		gperiodic.c -o gperiodic

do-build-NLS-on:
.for lang in ${LANGS}
	cd ${WRKSRC}/po && msgfmt -f -v -o ${lang}.mo ${lang}.po
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gperiodic ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/icons && ${INSTALL_DATA} gperiodic-crystal.png gperiodic.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)

do-install-NLS-on:
.for lang in ${LANGS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
