PORTNAME=	drawio
PORTVERSION=	28.0.6
PORTREVISION=	1
DISTVERSIONPREFIX=	x86_64-
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/jgraph/drawio-desktop/releases/download/v${PORTVERSION}/
EXTRACT_SUFX=	.rpm

MAINTAINER=	x636808@gmail.com
COMMENT=	Diagramming and whiteboarding desktop app
WWW=		https://drawio.com/

LICENSE=	APACHE20

USES=		desktop-file-utils electronfix:37 shared-mime-info

NO_BUILD=	yes
SUB_FILES=	drawio
NO_WRKSUBDIR=	yes

ELECTRONFIX_MAIN_EXECUTABLE=	drawio

do-install:
	cd ${WRKSRC}/opt/ && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${FIND} ${STAGEDIR}${PREFIX} -name '*.orig' -delete

.include <bsd.port.mk>
