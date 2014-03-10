# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	noegnud
PORTVERSION=	0.8.0
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION:C/(.\..*)\..*/\1/}_data-extras/
PKGNAMESUFFIX=	-addons
DISTFILES=	${DISTNAME}_data-tileset-absurd${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addons (tilesets and sound themes) for noeGNUd

USE_BZIP2=	yes
PLIST=		${WRKDIR}/pkg-plist
OPTIONS_DEFINE=	ABSURD ITAKURA ITAKURA ABIGABI GEODUCK LAGGED AOKI TFALCONSEYE NHS SFALCONSEYE
ABSURD_DESC=	absurd tileset
ITAKURA_DESC=	itakura tileset
MAZKO_DESC=	mazko tileset
ABIGABI_DESC=	abigabi tileset
GEODUCK_DESC=	geoduck tileset
LAGGED_DESC=	lagged tileset
AOKI_DESC=	aoki tileset
TFALCONSEYE_DESC=	falcons eye tileset
NHS_DESC=	nhs (qt) sound theme
SFALCONSEYE_DESC=	falcons eye sound theme

OPTIONS_DEFAULT=	ABSURD

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MABSURD}
DISTFILES=
.endif
.if ${PORT_OPTIONS:MITAKURA}
DISTFILES+=	${DISTNAME}_data-tileset-itakura${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MMAZKO}
DISTFILES+=	${DISTNAME}_data-tileset-mazko${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MABIGABI}
DISTFILES+=	${DISTNAME}_data-tileset-abigabi${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MGEODUCK}
DISTFILES+=	${DISTNAME}_data-tileset-geoduck${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MLAGGED}
DISTFILES+=	${DISTNAME}_data-tileset-lagged${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MAOKI}
DISTFILES+=	${DISTNAME}_data-tileset-aoki${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MTFALCONSEYE}
DISTFILES+=	${DISTNAME}_data-tileset-falconseye${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MNHS}
DISTFILES+=	${DISTNAME}_data-sound-nhs${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MSFALCONSEYE}
DISTFILES+=	${DISTNAME}_data-sound-falconseye${EXTRACT_SUFX}
.endif

NO_BUILD=	yes

pre-install:
	@${TOUCH} ${PLIST}
	@(cd ${WRKDIR} && ${FIND} ${DISTNAME} \! -type d) | ${SORT} | ${SED} -e 's:^:share/:' > ${PLIST}
	@(cd ${WRKDIR} && ${FIND} ${DISTNAME} -type d) | ${SORT} -r | ${SED} -e 's:^:@unexec rmdir %D/share/:' | ${SED} -e 's:$$: 2>/dev/null || true:' >> ${PLIST}

do-install:
	${CP} -R ${WRKSRC} ${PREFIX}/share

.include <bsd.port.mk>
