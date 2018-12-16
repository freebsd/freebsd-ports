# $FreeBSD$

PORTNAME=	liteide
DISTVERSIONPREFIX=	x
DISTVERSION=	34.2
CATEGORIES=	devel editors

MAINTAINER=	dg@syrec.org
COMMENT=	Simple, open source, cross-platform Go IDE

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	go:lang/go \
		gocode:devel/go-gocode

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_CONFLICTS_INSTALL=	${PORTNAME}
qt4_PKGNAMESUFFIX=	-qt4
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt4

USES=		gl qmake
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	visualfc
GH_TUPLE=	visualfc:gotools:77fd0f0:gotools/src/github.com/visualfc/gotools

.if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
USE_QT=		corelib gui moc_build network rcc_build uic_build webkit xml
PLIST_SUB+=	QT4="" NO_QT4="@comment "
.else
USES+=		qt:5
USE_QT=		buildtools_build core gui network printsupport widgets xml
PLIST_SUB+=	QT4="@comment " NO_QT4=""
.endif

WRKSRC_SUBDIR=	liteidex

PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

ICON_SIZES=	16 24 32 48 64 128

post-build:
	cd ${WRKSRC}/${GH_SUBDIR_gotools} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR_gotools}/gotools ${STAGEDIR}${PREFIX}/bin
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
	(cd ${WRKSRC:H} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
