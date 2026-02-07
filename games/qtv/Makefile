PORTNAME=	qtv
DISTVERSION=	1.15
CATEGORIES=	games

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	QuakeWorld match broadcasting tool
WWW=		https://github.com/QW-Group/qtv/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	QW-Group
USE_RC_SUBR=	${PORTNAME}

EXTRACT_AFTER_ARGS=	--exclude .git* \
			--exclude */.git* \
			--exclude build_cmake.sh \
			--exclude resources/example-configs/"PLACE YOUR QTV.BIN HERE" \
			--exclude resources/metaqtv* \
			--exclude tools*

QWDIR=		${PREFIX}/quake
SUB_LIST=	QWDIR=${QWDIR} QWUSER=${USERS}
USERS=		qw
GROUPS=		qw
PLIST_SUB=	QWGROUP=${GROUPS}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/resources/example-configs && \
		${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${QWDIR}
	${MV} ${STAGEDIR}${QWDIR}/${PORTNAME}/listip.cfg \
		${STAGEDIR}${QWDIR}/${PORTNAME}/listip.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/resources/example-configs/${PORTNAME}.cfg \
		${STAGEDIR}${QWDIR}/${PORTNAME}/${PORTNAME}.cfg.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/resources/example-configs/README.1ST \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
