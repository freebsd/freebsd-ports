# New ports collection makefile for:	54321
# Date created:				22 November 2001
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	54321
PORTVERSION=	1.0.2001.11.16
CATEGORIES=	games
MASTER_SITES=	http://www.nklein.com/products/54321/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	all size

post-extract:
	@${MKDIR} ${WRKSRC}/archs/FreeBSD
	@${CP} ${FILESDIR}/variables.GNU ${WRKSRC}/archs/FreeBSD

post-build:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" \
		${FILESDIR}/54321.sh > ${WRKSRC}/54321

do-install:
	@${MKDIR} ${PREFIX}/share/54321/bin/FreeBSD
	@${MKDIR} ${PREFIX}/share/54321/data
	@${CHMOD} -R 755 ${PREFIX}/share/54321
	@${INSTALL_PROGRAM} ${WRKSRC}/Release/bin/FreeBSD/54321 ${PREFIX}/share/54321/bin/FreeBSD
	@${INSTALL_DATA} ${WRKSRC}/Release/data/* ${PREFIX}/share/54321/data
	@${INSTALL_SCRIPT} ${WRKSRC}/54321 ${PREFIX}/bin

.include <bsd.port.mk>
