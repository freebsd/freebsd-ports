PORTNAME=	liteide
DISTVERSIONPREFIX=	x
DISTVERSION=	38.2
PORTREVISION=	18
CATEGORIES=	devel editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, open source, cross-platform Go IDE
WWW=		https://github.com/visualfc/liteide

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

USES=		dos2unix gl go:modules,no_targets,run qmake qt:5

DOS2UNIX_FILES=	src/utils/dlvclient/dlvclient.cpp \
		src/utils/dlvclient/dlvtypes.h

USE_GITHUB=	yes
GH_ACCOUNT=	visualfc

GH_TUPLE=	visualfc:gocode:v1.5.2:visualfc_gocode \
		visualfc:gotools:v1.5.3:visualfc_gotools \
		visualfc:gomod:v0.1.2:visualfc_gomod/vendor/github.com/visualfc/gomod \
		creack:pty:v1.1.9:creack_pty/vendor/github.com/creack/pty \
		golang:mod:v0.7.0:golang_mod/vendor/golang.org/x/mod \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.5.0:golang_tools/vendor/golang.org/x/tools \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		visualfc:goversion:v1.1.0:visualfc_goversion/vendor/github.com/visualfc/goversion \
		yuin:goldmark:v1.4.13:yuin_goldmark/vendor/github.com/yuin/goldmark

USE_CXXSTD=	c++14
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_QT=		buildtools:build core gui network printsupport widgets xml

SUB_FILES=	liteide

WRKSRC_SUBDIR=	liteidex

PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

ICON_SIZES=	16 24 32 48 64 128

post-extract:
	# Bundled, horribly outdated copy of QJsonDocument
	rm -r ${WRKSRC}/src/3rdparty/qjsonrpc/src/json/

post-build:
	${RLN} ${WRKSRC}/vendor ${WRKSRC_visualfc_gotools}
	cd ${WRKSRC_visualfc_gotools} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS}
	${RLN} ${WRKSRC}/vendor ${WRKSRC_visualfc_gocode}
	${RLN} ${WRKSRC_visualfc_gotools} ${WRKSRC_visualfc_gocode}/vendor/github.com/visualfc/gotools
	cd ${WRKSRC_visualfc_gocode} && \
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
