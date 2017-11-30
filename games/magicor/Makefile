# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicor
PORTVERSION=	1.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Old-school, puzzle game similar to Solomon's Key

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:devel/py-game

USES=		python:2.7 shebangfix
SHEBANG_FILES=	*.py
NO_BUILD=	yes
NO_ARCH=	yes

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
EDITOR_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:x11-toolkits/py-gtk2

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
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	@cd ${WRKSRC}/magicor && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/magicor/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/magicor
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor.py ${STAGEDIR}${PREFIX}/bin/magicor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor.conf \
		${STAGEDIR}${PREFIX}/etc/magicor/magicor.conf.sample

do-install-EDITOR-on:
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor-LevelEditor.py ${STAGEDIR}${PREFIX}/bin/magicor-editor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor-editor.conf \
		${STAGEDIR}${PREFIX}/etc/magicor/magicor-editor.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
