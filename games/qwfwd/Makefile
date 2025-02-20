PORTNAME=	qwfwd
DISTVERSION=	1.2.20240216
CATEGORIES=	games

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	QuakeWorld proxy
WWW=		https://github.com/QW-Group/qwfwd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	QW-Group
GH_TAGNAME=	f657ff7
USE_RC_SUBR=	${PORTNAME}

EXTRACT_AFTER_ARGS=	--exclude .git* \
			--exclude */.git* \
			--exclude build_cmake.sh \
			--exclude tools*

SUB_LIST=	QWUSER=${USERS}
USERS=		qwfwd
GROUPS=		qwfwd
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/resources/example-configs/${PORTNAME}.cfg \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.cfg.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
