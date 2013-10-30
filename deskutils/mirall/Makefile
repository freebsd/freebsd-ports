# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	mirall
PORTVERSION=	1.4.2
CATEGORIES=	deskutils
MASTER_SITES=	http://download.owncloud.com/download/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	The ownCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libocsync.so:${PORTSDIR}/net/owncloud-csync \
		libinotify.so:${PORTSDIR}/devel/libinotify \
		libqtkeychain.so:${PORTSDIR}/security/qtkeychain

USES=		cmake:outsource pkgconfig gmake
USE_BZIP2=
USE_QT4=	corelib dbus gui linguist moc network qmake qtestlib rcc uic webkit xml
CMAKE_ENV=	CSYNC_DIR=${LOCALBASE}
CMAKE_ARGS=	-DCSYNC_INCLUDE_PATH:STRING=${LOCALBASE}/include/ocsync/
USE_GCC=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_USE=	TEX=latex:build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	WITH_DOC=TRUE
ALL_TARGET=	all doc-html doc-pdf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/latex/ownCloudClientManual.pdf ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC}/doc/html/unthemed ; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html
.endif

.include <bsd.port.mk>
