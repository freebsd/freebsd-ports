# New ports collection makefile for:	noegnud-addons
# Date created:				7 April 2004
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	noegnud
PORTVERSION=	0.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-addons
DISTFILES=	${DISTNAME}_data-tileset-absurd${EXTRACT_SUFX}

MAINTAINER=	llwang@infor.org
COMMENT=	The addons (tilesets and sound themes) for noeGNUd

PLIST=		${WRKDIR}/pkg-plist
OPTIONS=	TILESET_ABSURD		"absurd tileset"		on \
		TILESET_ITAKURA		"itakura tileset"		off \
		TILESET_MAZKO		"mazko tileset"			off \
		TILESET_ABIGABI		"abigabi tileset"		off \
		TILESET_GEODUCK		"geoduck tileset"		off \
		TILESET_LAGGED		"lagged tileset"		off \
		TILESET_AOKI		"aoki tileset"			off \
		TILESET_FALCONSEYE	"falcons eye tileset"		off \
		SOUND_NHS		"nhs (qt) sound theme"		off \
		SOUND_FALCONSEYE	"falcons eye sound theme"	off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TILESET_ABSURD)
DISTFILES=
.endif
.if defined(WITH_TILESET_ITAKURA)
DISTFILES+=	${DISTNAME}_data-tileset-itakura${EXTRACT_SUFX}
.endif
.if defined(WITH_TILESET_MAZKO)
DISTFILES+=	${DISTNAME}_data-tileset-mazko${EXTRACT_SUFX}
.endif
.if defined(WITH_TILESET_ABIGABI)
DISTFILES+=	${DISTNAME}_data-tileset-abigabi${EXTRACT_SUFX}
.endif
.if defined(WITH_TILESET_GEODUCK)
DISTFILES+=	${DISTNAME}_data-tileset-geoduck${EXTRACT_SUFX}
.endif
.if defined(WITH_TILESET_LAGGED)
DISTFILES+=	${DISTNAME}_data-tileset-lagged${EXTRACT_SUFX}
.endif
.if defined(WITH_TILESET_AOKI)
DISTFILES+=	${DISTNAME}_data-tileset-aoki${EXTRACT_SUFX}
.endif
.if defined(WITH_TILESET_FALCONSEYE)
DISTFILES+=	${DISTNAME}_data-tileset-falconseye${EXTRACT_SUFX}
.endif
.if defined(WITH_SOUND_NHS)
DISTFILES+=	${DISTNAME}_data-sound-nhs${EXTRACT_SUFX}
.endif
.if defined(WITH_SOUND_FALCONSEYE)
DISTFILES+=	${DISTNAME}_data-sound-falconseye${EXTRACT_SUFX}
.endif

NO_BUILD=	yes

pre-install:
	@${TOUCH} ${PLIST}
	@(cd ${WRKDIR} && ${FIND} ${DISTNAME} \! -type d) | ${SORT} | ${SED} -e 's:^:share/:' > ${PLIST}
	@(cd ${WRKDIR} && ${FIND} ${DISTNAME} -type d) | ${SORT} -r | ${SED} -e 's:^:@unexec rmdir %D/share/:' | ${SED} -e 's:$$: 2>/dev/null || true:' >> ${PLIST}

do-install:
	${CP} -R ${WRKSRC} ${PREFIX}/share

.include <bsd.port.post.mk>
