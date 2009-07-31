# New ports collection makefile for:	png2html
# Date created:				11 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	png2html
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Takes a PNG image and transforms it into HTML

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		gd.4:${PORTSDIR}/graphics/gd

PLIST_FILES=	bin/png2html

do-configure:
		@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
		@${SED} -e 's|CHANGE_ME|${PREFIX}|' \
			< ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/png2html ${PREFIX}/bin

.include <bsd.port.mk>
