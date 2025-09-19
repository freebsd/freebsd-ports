PORTNAME=	liteide
DISTVERSIONPREFIX=	x
DISTVERSION=	38.4
CATEGORIES=	devel editors
MASTER_SITES=	https://go.googlesource.com/sync/+archive/refs/tags/:errgroup
DISTFILES=	v0.17.0/errgroup.tar.gz:errgroup

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, open source, cross-platform Go IDE
WWW=		https://github.com/visualfc/liteide

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		dos2unix gl go:modules,no_targets,run qmake qt:5

DOS2UNIX_FILES=	${PORTNAME}.desktop \
		src/utils/dlvclient/dlvclient.cpp \
		src/utils/dlvclient/dlvtypes.h

USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	visualfc
GH_TUPLE=	visualfc:gocode:v1.5.2:visualfc_gocode \
		visualfc:gotools:45f301a:visualfc_gotools \
		visualfc:gomod:v0.1.2:visualfc_gomod/vendor/github.com/visualfc/gomod \
		visualfc:goversion:v1.1.0:visualfc_goversion/vendor/github.com/visualfc/goversion \
		creack:pty:v1.1.24:creack_pty/vendor/github.com/creack/pty \
		golang:mod:v0.28.0:golang_mod/vendor/golang.org/x/mod \
		golang:sys:v0.36.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.37.0:golang_tools/vendor/golang.org/x/tools \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		yuin:goldmark:v1.7.13:yuin_goldmark/vendor/github.com/yuin/goldmark

USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_QT=		buildtools:build core gui network printsupport widgets xml

SUB_FILES=	${PORTNAME}

WRKSRC_SUBDIR=	${PORTNAME}x

PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

ICON_SIZES=	16 24 32 48 64 128

post-extract:
	# Bundled, horribly outdated copy of QJsonDocument
	${RM} -r ${WRKSRC}/src/3rdparty/qjsonrpc/src/json/
	${MKDIR} ${WRKSRC}/vendor/golang.org/x/sync/errgroup
	${MV} ${WRKDIR}/errgroup.go ${WRKSRC}/vendor/golang.org/x/sync/errgroup

post-build:
	${RLN} ${WRKSRC}/vendor ${WRKSRC_visualfc_gotools}
	(cd ${WRKSRC_visualfc_gotools} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS})
	${RLN} ${WRKSRC}/vendor ${WRKSRC_visualfc_gocode}
	${RLN} ${WRKSRC_visualfc_gotools} ${WRKSRC_visualfc_gocode}/vendor/github.com/visualfc/gotools
	(cd ${WRKSRC_visualfc_gocode} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS})

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME} \
		 ${STAGEDIR}${PREFIX}/share/applications \
		 ${ICON_SIZES:C|(.+)|${STAGEDIR}${PREFIX}/share/icons/hicolor/\1x\1/apps|}
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/gocode \
		${GO_WRKDIR_BIN}/gotools ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	(cd ${WRKSRC}/deploy && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/os_deploy/freebsd && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RM} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/*.a
.for sz in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/src/liteapp/images/${PORTNAME}${sz}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/${PORTNAME}.png
.endfor

post-install-DOCS-on:
	(cd ${WRKSRC:H} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
