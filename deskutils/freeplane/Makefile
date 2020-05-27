# Created by: Loïc Bartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeplane
DISTVERSION=	1.8.5
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/archive/${PORTVERSION}
DISTNAME=	${PORTNAME}_bin-${PORTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Free mind mapping and knowledge management software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cpe zip

USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! ( -name freeplane\.sh* -or -name license\.txt -or -name *\.bat -or -name *\.exe )"
# Install freeplane.sh with the right permission, link to it to bin/
# and let it resolve the path to DATADIR automatically.
	${INSTALL_SCRIPT} ${WRKSRC}/freeplane.sh ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/freeplane.sh ${STAGEDIR}${PREFIX}/bin/freeplane

.include <bsd.port.mk>
