# New ports collection makefile for:	magicor
# Date created:		09 Jul 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	magicor
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Old-school, puzzle game similar to Solomon's Key

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

OPTIONS=	EDITOR	"Enable editor"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EDITOR)
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
.if !defined(WITHOUT_EDITOR)
	${INSTALL_SCRIPT} ${WRKSRC}/Magicor-LevelEditor.py ${PREFIX}/bin/magicor-editor
	${INSTALL_DATA} ${WRKSRC}/etc/magicor-editor.conf \
		${PREFIX}/etc/magicor/magicor-editor.conf.dist
	if [ ! -f ${PREFIX}/etc/magicor/magicor-editor.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/magicor/magicor-editor.conf.dist \
			${PREFIX}/etc/magicor/magicor-editor.conf; \
	fi
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
