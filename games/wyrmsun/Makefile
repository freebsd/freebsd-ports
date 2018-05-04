# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wyrmsun
PORTVERSION=	3.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Strategy game based on history, mythology and fiction

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	wyrmgus:games/wyrmgus

USE_GITHUB=	yes
GH_ACCOUNT=	Andrettin
GH_PROJECT=	Wyrmsun

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/appdata/${PORTNAME}.appdata.xml
PORTDATA=	*
PORTDOCS=	*

SUB_FILES=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|wyrmgus -d /usr/share/wyrmsun|${PORTNAME}|' \
		${WRKSRC}/linux/wyrmsun.desktop

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics maps music oaml.defs \
		scripts sounds translations" ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/linux/wyrmsun.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/linux/wyrmsun.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
