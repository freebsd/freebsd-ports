# $FreeBSD$

PORTNAME=	liteide
DISTVERSIONPREFIX=	x
DISTVERSION=	36.2
PORTREVISION=	2
CATEGORIES=	devel editors

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple, open source, cross-platform Go IDE

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		gl go:modules,no_targets,run qmake qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	visualfc
GH_TUPLE=	visualfc:gocode:15064618fb33:visualfc_gocode \
		visualfc:gotools:b83b3e5a55ac:visualfc_gotools

USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_QT=		buildtools_build core gui network printsupport widgets xml

SUB_FILES=	liteide

WRKSRC_SUBDIR=	liteidex

PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

ICON_SIZES=	16 24 32 48 64 128

post-build:
	cd ${WRKSRC_visualfc_gocode} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS}
	cd ${WRKSRC_visualfc_gotools} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/liteide
	${MV} ${STAGEDIR}${PREFIX}/bin/liteide ${STAGEDIR}${PREFIX}/libexec/liteide
	${INSTALL_SCRIPT} ${WRKDIR}/liteide ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/gocode ${STAGEDIR}${PREFIX}/libexec/liteide
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/gotools ${STAGEDIR}${PREFIX}/libexec/liteide
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/liteide.desktop ${STAGEDIR}${PREFIX}/share/applications
	(cd ${WRKSRC}/deploy && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/os_deploy/freebsd && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RM} ${STAGEDIR}${PREFIX}/lib/liteide/*.a
.for sz in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${INSTALL_DATA} ${WRKSRC}/src/liteapp/images/liteide${sz}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/liteide.png
.endfor

post-install-DOCS-on:
	cd ${WRKSRC:H} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
