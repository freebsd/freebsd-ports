# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	daimonin-music
PORTVERSION=	20120402
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/daimonin/Addon%20packs/Music/
DISTNAME=	AllMusic
DIST_SUBDIR=	daimonin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music for daimonin client

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
NO_BUILD=	yes
USES=		zip
NO_ARCH=	yes

MYDATADIR=	${PREFIX}/share/daimonin

post-extract:
	@${MV} ${WRKDIR}/media/media.txt ${WRKDIR}/media/media-music.txt
	@${RM} -f ${WRKDIR}/media/orchestral.ogg

do-install:
	@${MKDIR} ${STAGEDIR}${MYDATADIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} media ${STAGEDIR}${MYDATADIR}/)

.include <bsd.port.mk>
