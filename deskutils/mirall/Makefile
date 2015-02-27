# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	mirall
PORTVERSION=	1.7.1
CATEGORIES=	deskutils
MASTER_SITES=	http://download.owncloud.com/desktop/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt based sync client for OwnCloud

LICENSE=	GPLv2

LIB_DEPENDS=	libinotify.so:${PORTSDIR}/devel/libinotify \
		libqtkeychain.so:${PORTSDIR}/security/qtkeychain \
		libneon.so:${PORTSDIR}/www/neon

USES=		cmake:outsource compiler:c++11-lib gmake pkgconfig tar:bzip2
USE_QT4=	corelib dbus gui network qtestlib webkit xml \
		linguisttools_build moc_build qmake_build rcc_build uic_build \
		sql-sqlite3_run
USE_SQLITE=	3
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=ON \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CFLAGS+=	-I${WRKSRC}/csync/src/httpbf/src -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_USE=		tex=dvipsk:build,latex:build
DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

.include <bsd.port.mk>
