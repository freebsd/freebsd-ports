# Created by: Loïc Bartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	freeplane
DISTVERSION=	1.7.10
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/archive/${PORTVERSION}
DISTNAME=	${PORTNAME}_bin-${PORTVERSION}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Free mind mapping and knowledge management software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cpe zip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
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
