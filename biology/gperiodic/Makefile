# New ports collection makefile for:	gperiodic
# Date created:				16 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gperiodic
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://koti.welho.com/jfrantz/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a periodic table of the elements

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gtk20
USE_REINPLACE=	yes
ALL_TARGET=	${PORTNAME}

LANGS=		da fr pl sv tr

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=|CC?=|g ; \
		 s|^CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile

post-build:
.for lang in ${LANGS}
	cd ${WRKSRC}/po && msgfmt -f -v -o ${lang}.mo ${lang}.po
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gperiodic ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/gperiodic.desktop \
		${PREFIX}/share/gnome/applications
	@${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gperiodic.png \
		${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gperiodic-crystal.png \
		${PREFIX}/share/gnome/pixmaps
.for lang in ${LANGS}
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
