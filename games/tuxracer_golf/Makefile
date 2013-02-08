# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxracer_golf
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A golf course theme for Tux Racer

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		overwrite a file owned by tuxracer: share/tuxracer/courses/common/buttprint.rgb

RUN_DEPENDS=	tuxracer:${PORTSDIR}/games/tuxracer

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
