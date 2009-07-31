# New ports collection makefile for:	gperiodic
# Date created:				16 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#    $MCom: ports/biology/gperiodic/Makefile,v 1.1 2006/09/29 23:42:13 ahze Exp $

PORTNAME=	gperiodic
PORTVERSION=	2.0.10
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	http://www.frantz.fi/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a periodic table of the elements

USE_GNOME=	gtk20
USE_GETTEXT=	yes

LANGS=		da fr gl it pl ru sv tr

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} `pkg-config --cflags --libs gtk+-2.0` \
		gperiodic.c -o gperiodic
.for lang in ${LANGS}
	cd ${WRKSRC}/po && msgfmt -f -v -o ${lang}.mo ${lang}.po
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gperiodic ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gperiodic.desktop \
		${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gperiodic.png \
		${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gperiodic-crystal.png \
		${PREFIX}/share/pixmaps
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
