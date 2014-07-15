# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	mirall
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://download.owncloud.com/desktop/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The ownCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libinotify.so:${PORTSDIR}/devel/libinotify \
		libqtkeychain.so:${PORTSDIR}/security/qtkeychain \
		libneon.so:${PORTSDIR}/www/neon29

USES=		cmake:outsource compiler:c++11-lang gmake pkgconfig tar:bzip2
USE_QT4=	corelib dbus gui network qtestlib webkit xml \
		linguist_build moc_build qmake_build rcc_build uic_build
CMAKE_ENV=	INOTIFY_LIB="${LOCALBASE}/lib"
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:STRING=${MANPREFIX}/man/
USE_SQLITE=	3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CONFLICTS=	owncloud-csync-[0-9]*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_USE=		TEX=latex:build
DOCS_CMAKE_ON=		WITH_DOC=true
DOCS_ALL_TARGET=	all doc-html doc-pdf

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

post-build:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc/latex && ${INSTALL_DATA} *.pdf \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@(cd ${INSTALL_WRKSRC}/doc/html/unthemed && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/html)
.endif

.include <bsd.port.mk>
