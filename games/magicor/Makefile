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

PORTDOCS=	README

DESKTOP_ENTRIES="Magicor" \
		"Old-school, puzzle game similar to Solomon's Key" \
		"" \
		"magicor" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	EDITOR DOCS
OPTIONS_DEFAULT=EDITOR
EDITOR_DESC=	Enable editor

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEDITOR}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=	EDITOR=""
.else
PLIST_SUB+=	EDITOR="@comment "
.endif

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
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}
	mkdir ${PYTHON_SITELIBDIR}/magicor
	cd ${WRKSRC}/magicor && ${COPYTREE_SHARE} . ${PYTHON_SITELIBDIR}/magicor
	${MKDIR} ${PREFIX}/etc/magicor
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor.py ${PREFIX}/bin/magicor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor.conf \
		${PREFIX}/etc/magicor/magicor.conf.dist
	if [ ! -f ${PREFIX}/etc/magicor/magicor.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/magicor/magicor.conf.dist \
			${PREFIX}/etc/magicor/magicor.conf; \
	fi
.if ${PORT_OPTIONS:MEDITOR}
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor-LevelEditor.py ${PREFIX}/bin/magicor-editor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor-editor.conf \
		${PREFIX}/etc/magicor/magicor-editor.conf.dist
	if [ ! -f ${PREFIX}/etc/magicor/magicor-editor.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/magicor/magicor-editor.conf.dist \
			${PREFIX}/etc/magicor/magicor-editor.conf; \
	fi
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
