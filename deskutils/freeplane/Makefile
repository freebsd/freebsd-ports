PORTNAME=	freeplane
DISTVERSION=	1.12.14
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable
DISTNAME=	${PORTNAME}_bin-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Free mind mapping and knowledge management software
WWW=		https://www.freeplane.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	bash:shells/bash

USES=		cpe desktop-file-utils java shebangfix zip

SHEBANG_FILES=	${WRKSRC}/freeplane.sh

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	freeplane freeplane.desktop
SUB_LIST=	DATADIR=${DATADIR} \
		PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"! ( -name license\.txt -or -name *\.bat -or -name *\.exe -or -name *\.orig -or -name *\.bak -or -name freeplane.sh -or -name *\.dll -or -name *\.so )"
	${INSTALL_DATA} ${WRKDIR}/freeplane.desktop ${STAGEDIR}${DESKTOPDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/freeplane.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/freeplane ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
