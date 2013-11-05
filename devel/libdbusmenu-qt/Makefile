# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdbusmenu-qt
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 implementation of the DBusMenu protocol

LICENSE=	LGPL20

USE_QT4=	corelib dbus gui \
		moc_build qmake_build rcc_build uic_build
FETCH_ARGS=	-Fpr
USE_BZIP2=	yes
USES=		cmake:outsource
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GENDOCS
GENDOCS_DESC=	Build documentation (requires doxygen)
.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	GENDOCS
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGENDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CMAKE_ARGS+=	-DDOC_INSTALL_DIR:PATH="${DOCSDIR_REL}"
PLIST_SUB+=	GENDOCS=""
.else
CMAKE_ARGS+=	-DWITH_DOC:BOOL=OFF
PLIST_SUB+=	GENDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_SUFFIX}/data/' \
		-e '/tests/ d' -e '/tools/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
