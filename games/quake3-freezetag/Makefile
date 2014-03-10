# Created by: pat@databits.net
# $FreeBSD$

PORTNAME=	freezetag
PORTVERSION=	1.51b
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pat
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	q3freeze${PORTVERSION:S/.//}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena Mod: Freeze Tag

WRKSRC=		${WRKDIR}/freeze

USES=		zip
NO_BUILD=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

NO_STAGE=	yes
.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

.if exists(${Q3DIR}/missionpack/pak1.pk3)
WITH_MISSIONPACK=	yes
.endif

.if defined(WITH_MISSIONPACK)
PLIST_SUB+=	MISSIONPACK=""
.else
PLIST_SUB+=	MISSIONPACK="@comment "
.endif

do-install:
	@${MKDIR} ${DATADIR}
.for f in description.txt freeze.cfg freeze0.pk3 freeze1.pk3 ft.config
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if defined(WITH_MISSIONPACK)
	@${INSTALL_DATA} ${WRKSRC}/missionpack/freeze_ta0.pk3 \
		${Q3DIR}/missionpack
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
