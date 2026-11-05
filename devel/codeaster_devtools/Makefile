PORTNAME=	devtools
DISTVERSION=	15.1.23
CATEGORIES=	devel
PKGNAMEPREFIX=	codeaster_

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Development Tools for Code_Aster
WWW=		https://www.code-aster.org/

LICENSE=	GPLv2

BUILD_RUN_DEPENDS=	bash:shells/bash

USES=		gettext-runtime:run python:run shebangfix tar:bz2
SHEBANG_GLOB=	*

USE_GITLAB=	yes
GL_ACCOUNT=	codeaster

NO_ARCH=	yes
NO_BUILD=	yes

ASTER_ROOT=	${PREFIX}/aster
INSTDIR=	${ASTER_ROOT}/dev/codeaster/devtools
SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR=${INSTDIR}

pre-configure:
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/lib/aslint/check_files.py

do-install:
	@${MKDIR} ${STAGEDIR}${INSTDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTDIR}

.include <bsd.port.mk>
