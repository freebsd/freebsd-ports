# New ports collection makefile for:	tuxracer_golf
# Date created:				17 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tuxracer_golf
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.joeysmith.com/~milo/tuxracer/
DISTNAME=	golf
EXTRACT_SUFX=	.gz

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A golf theme for Tux Racer

BUILD_DEPENDS=	tuxracer:${PORTSDIR}/games/tuxracer

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB+=	"MV=${MV}"

TEXTURES=	buttprint buttstart buttstop cloudyback cloudybottom \
	cloudyfront cloudyleft cloudyright envmap \
	herring_standard herringrunicon ice nightback \
	nightbottom nightenv nightfront nightleft nightright nighttop \
	rock shrub snow snowparticles sunnyback \
	sunnybottom sunnyfront sunnyleft sunnyright sunnytop tree \
	tree_barren

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/common.old
	-@${CP} ${PREFIX}/share/tuxracer/courses/common/*rgb \
		${DATADIR}/common.old
.for i in ${TEXTURES}
	@${INSTALL_DATA} ${WRKDIR}/$i.rgb \
		${PREFIX}/share/tuxracer/courses/common
.endfor

.include <bsd.port.mk>
