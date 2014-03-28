# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	mirall
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://download.owncloud.com/desktop/stable/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	The ownCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libocsync.so:${PORTSDIR}/net/owncloud-csync \
		libinotify.so:${PORTSDIR}/devel/libinotify \
		libqtkeychain.so:${PORTSDIR}/security/qtkeychain

USES=		cmake:outsource pkgconfig gmake compiler:c++11-lang tar:bzip2
USE_QT4=	corelib dbus gui linguist moc network qmake qtestlib rcc uic webkit xml
CMAKE_ENV=	CSYNC_DIR=${LOCALBASE} INOTIFY_LIB=${LOCALBASE}/lib
CMAKE_ARGS=	-DCSYNC_INCLUDE_PATH:STRING=${LOCALBASE}/include/ocsync/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_USE=	TEX=latex:build
DOCS_CMAKE_ON=	WITH_DOC=true
DOCS_ALL_TARGET=	doc-html doc-pdf

PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/latex/ownCloudClientManual.pdf ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc/html/unthemed && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)
	${MV} ${STAGEDIR}${PREFIX}/etc/ownCloud/sync-exclude.lst ${STAGEDIR}${PREFIX}/etc/ownCloud/sync-exclude.lst.sample
.endif

.include <bsd.port.mk>
