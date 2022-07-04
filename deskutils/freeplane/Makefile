# Created by: Loïc Bartoletti <lbartoletti@FreeBSD.org>

PORTNAME=	freeplane
DISTVERSION=	1.10.3
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable
DISTNAME=	${PORTNAME}_bin-${PORTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Free mind mapping and knowledge management software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	bash:shells/bash

USES=		cpe zip shebangfix
SHEBANG_FILES=	${WRKSRC}/freeplane.sh
USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! ( -name license\.txt -or -name *\.bat -or -name *\.exe )"
# Install freeplane.sh with the right permission
	${SED} -e 's|%%DATADIR%%|${DATADIR}|' < ${FILESDIR}/freeplane.in > \
		${WRKSRC}/freeplane
	${INSTALL_SCRIPT} ${WRKSRC}/freeplane ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
