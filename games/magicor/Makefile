# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicor
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Old-school, puzzle game similar to Solomon's Key

LICENSE=	unknown
LICENSE_NAME=	Public Domain
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Magicor" \
		"Old-school, puzzle game similar to Solomon's Key" \
		"" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	EDITOR DOCS
OPTIONS_DEFAULT=EDITOR
OPTIONS_SUB=	yes

EDITOR_DESC=	Enable editor
EDITOR_RUN_DEPEND=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|###CONFIG_PATH###|${PREFIX}/etc/magicor/magicor.conf|' \
		${WRKSRC}/Magicor.py
	@${REINPLACE_CMD} -e 's|###CONFIG_PATH###|${PREFIX}/etc/magicor/magicor-editor.conf|' \
		${WRKSRC}/Magicor-LevelEditor.py
	@${REINPLACE_CMD} -e '1,1 s|/usr/bin/python|/usr/bin/env python|' \
		${WRKSRC}/Magicor.py ${WRKSRC}/Magicor-LevelEditor.py
	@${REINPLACE_CMD} -e 's|###SHARE_PATH###|${DATADIR}|' ${WRKSRC}/etc/*.conf
	@${FIND} ${WRKSRC}/magicor -name "*.pyc" -delete

do-install:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/magicor && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/magicor/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/magicor
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor.py ${STAGEDIR}${PREFIX}/bin/magicor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor.conf \
		${STAGEDIR}${PREFIX}/etc/magicor/magicor.conf.dist
.if ${PORT_OPTIONS:MEDITOR}
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor-LevelEditor.py ${STAGEDIR}${PREFIX}/bin/magicor-editor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor-editor.conf \
		${STAGEDIR}${PREFIX}/etc/magicor/magicor-editor.conf.dist
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
