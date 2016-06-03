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

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}
PORTDATA=	*

OPTIONS_DEFINE=	ABSURD ITAKURA ITAKURA ABIGABI GEODUCK LAGGED AOKI \
		TFALCONSEYE NHS SFALCONSEYE
ABSURD_DESC=	absurd tileset
ITAKURA_DESC=	itakura tileset
ITAKURA_DISTFILES=	${DISTNAME}_data-tileset-itakura${EXTRACT_SUFX}
MAZKO_DESC=	mazko tileset
MAZKO_DISTFILES=	${DISTNAME}_data-tileset-mazko${EXTRACT_SUFX}
ABIGABI_DESC=	abigabi tileset
ABIGABI_DISTFILES=	${DISTNAME}_data-tileset-abigabi${EXTRACT_SUFX}
GEODUCK_DESC=	geoduck tileset
GEODUCK_DISTFILES=	${DISTNAME}_data-tileset-geoduck${EXTRACT_SUFX}
LAGGED_DESC=	lagged tileset
LAGGED_DISTFILES=	${DISTNAME}_data-tileset-lagged${EXTRACT_SUFX}
AOKI_DESC=	aoki tileset
AOKI_DISTFILES=		${DISTNAME}_data-tileset-aoki${EXTRACT_SUFX}
TFALCONSEYE_DESC=	falcons eye tileset
TFALCONSEYE_DISTFILES=	${DISTNAME}_data-tileset-falconseye${EXTRACT_SUFX}
NHS_DESC=	nhs (qt) sound theme
NHS_DISTFILES=		${DISTNAME}_data-sound-nhs${EXTRACT_SUFX}
SFALCONSEYE_DESC=	falcons eye sound theme
SFALCONSEYE_DISTFILES=	${DISTNAME}_data-sound-falconseye${EXTRACT_SUFX}

OPTIONS_DEFAULT=	ABSURD

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MABSURD}
DISTFILES=	# empty
.endif

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
