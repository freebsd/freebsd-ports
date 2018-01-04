# $FreeBSD$

PORTNAME=	liteide
DISTVERSIONPREFIX=	x
DISTVERSION=	33.1
CATEGORIES=	devel editors

MAINTAINER=	dg@syrec.org
COMMENT=	Simple, open source, cross-platform Go IDE

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

WRKSRC_SUBDIR=	liteidex

USES=		qmake
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	visualfc
LDFLAGS+=	-Wl,--as-needed

PORTDOCS=	CONTRIBUTORS README.md

INSTALLS_ICONS=	yes
ICON_SIZES=	16 24 32 48 64 128

OPTIONS_DEFINE=		DEBUG DOCS
OPTIONS_SINGLE=		QT
OPTIONS_SINGLE_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT5
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ENABLE=	debug

QT4_USE=	QT4=corelib,gui,network,webkit,xml,moc_build,rcc_build,uic_build
QT5_USE=	QT5=core,gui,network,printsupport,widgets,xml,buildtools_build

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
