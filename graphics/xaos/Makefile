# Created by: Joseph Koshy <koshy@india.hp.com>
# $FreeBSD$

PORTNAME=	xaos
DISTVERSIONPREFIX=	release-
DISTVERSION=	4.0
CATEGORIES=	graphics math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time interactive fractal browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl qmake qt:5
USE_QT=		core gui opengl widgets buildtools_build linguisttools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	xaos-project
GH_PROJECT=	XaoS

QMAKE_ARGS+=	INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib

DESKTOP_ENTRIES=	"XaoS" \
			"" \
			"${PREFIX}/share/pixmaps/xaos.png" \
			"xaos" \
			"" \
			false

OPTIONS_DEFINE=		DOCS EXAMPLES NLS TUTORIAL
OPTIONS_DEFAULT=	TUTORIAL
OPTIONS_SUB=		yes

TUTORIAL_DESC=	Tutorial fractal sequences

post-install:
	# HACK: original "install" target missing
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xaos ${STAGEDIR}${PREFIX}/bin/xaos
	${INSTALL_DATA} ${WRKSRC}/src/ui/images/xaosbig.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/xaos.png

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/doc/xaos.6 \
		${STAGEDIR}${MANPREFIX}/share/man/man6/xaos.6

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install-NLS-on:
	# catalogs
	(cd ${WRKSRC}/catalogs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/XaoS/catalogs)
	# translation files
	(cd ${WRKSRC}/i18n && ${COPYTREE_SHARE} \
		"*.qm" ${STAGEDIR}${PREFIX}/share/XaoS/i18n)

post-install-TUTORIAL-on:
	(cd ${WRKSRC}/tutorial && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/XaoS/tutorial)

.include <bsd.port.mk>
