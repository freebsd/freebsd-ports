# Created by: nivit@email.it
# $FreeBSD$

PORTNAME=	slimeforest
PORTVERSION=	158
PORTREVISION=	0
CATEGORIES=	japanese education games linux
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/${DIST_SUBDIR}/ \
		http://lrnj.com/
DISTNAME=	sfa
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	NES RPG game for learning KANA and KANJI (Linux version)

LICENSE=	GPLv2

NO_BUILD=	yes

PLIST_SUB=	BINMODE=${BINMODE}

SUB_FILES=	${PORTNAME}.sh

USES=		linux
USE_LINUX=	sdlimage

WRKSRC=		${WRKDIR}/slimeforest

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/jquest && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		'! -name *\.bak -and ! -name *\.txt -and ! -name jquest64')
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}.sh
	@${LN} -sf slimeforest.sh ${STAGEDIR}${PREFIX}/bin/slimeforest-fs
	@${LN} -sf slimeforest.sh ${STAGEDIR}${PREFIX}/bin/slimeforest-win

.include <bsd.port.mk>
