# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdbusmenu-qt
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 implementation of the DBusMenu protocol

LICENSE=	LGPL20

USE_QT4=	dbus gui xml \
		moc_build qmake_build rcc_build uic_build
FETCH_ARGS=	-Fpr
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*
CMAKE_ARGS+=	-DDOC_INSTALL_DIR:PATH="${DOCSDIR_REL}"
.else
CMAKE_ARGS+=	-DWITH_DOC:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_SUFFIX}/data/' \
		-e '/tests/ d' -e '/tools/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
