# $FreeBSD$

PORTNAME=	liteide
DISTVERSIONPREFIX=	x
DISTVERSION=	34
CATEGORIES=	devel editors

MAINTAINER=	dg@syrec.org
COMMENT=	Simple, open source, cross-platform Go IDE

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_CONFLICTS_INSTALL=	${PORTNAME}
qt4_PKGNAMESUFFIX=	-qt4
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt4

USES=		qmake
USE_GL=		gl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	visualfc

.if ${FLAVOR} == qt4
USES+=		qt:4
USE_QT=		corelib gui moc_build network rcc_build uic_build webkit xml
PLIST_SUB+=	QT4="" NO_QT4="@comment "
.else
USES+=		qt:5
USE_QT=		buildtools_build core gui network printsupport widgets xml
PLIST_SUB+=	QT4="@comment " NO_QT4=""
.endif

WRKSRC_SUBDIR=	liteidex

PORTDOCS=	CONTRIBUTORS README.md

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

ICON_SIZES=	16 24 32 48 64 128

post-install:
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
