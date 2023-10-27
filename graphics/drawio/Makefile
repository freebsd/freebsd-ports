PORTNAME=	drawio
PORTVERSION=	22.0.3
DISTVERSIONPREFIX=	x86_64-
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/jgraph/drawio-desktop/releases/download/v${PORTVERSION}/
EXTRACT_SUFX=	.rpm

MAINTAINER=	636808@mail.ru
COMMENT=	Diagramming and whiteboarding desktop app
WWW=		https://drawio.com/

LICENSE=	APACHE20

USES=		desktop-file-utils electronfix:25 shared-mime-info

ELECTRONFIX_MAIN_EXECUTABLE=	drawio
SUB_FILES=	drawio
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}/opt/ && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${FIND} ${STAGEDIR}${PREFIX} -name '*.orig' -delete

.include <bsd.port.mk>
