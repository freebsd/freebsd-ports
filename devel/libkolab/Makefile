# $FreeBSD$

PORTNAME=	libkolab
PORTVERSION=	0.6.3
PORTREVISION=	6
CATEGORIES=	devel kde
MASTER_SITES=	http://mirror.kolabsys.com/pub/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced Kolab Object Handling Library

# The code in kolabformatV2 is LGPL21, but we consider the library
# itself to be LGPL3-licensed (and so are all the installed headers).
LICENSE=	LGPL3

PORTSCOUT=	limit:^0\.

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libkolabxml.so:textproc/libkolabxml \
		libxerces-c.so:textproc/xerces-c3

# TODO: Conditionally enable the bindings based on OPTIONs.
CMAKE_ARGS=	-DBUILD_TESTS:BOOL=OFF \
		-DPHP_BINDINGS:BOOL=OFF \
		-DPYTHON_BINDINGS:BOOL=OFF \
		-DUSE_LIBCALENDARING:BOOL=OFF
USES=		cmake:outsource kde:4
USE_KDE=	automoc4 kdelibs pimlibs
USE_LDCONFIG=	yes
USE_QT4=	corelib dbus gui network svg xml \
		moc_build qmake_build rcc_build uic_build
# Fix build of desktuils/kdepim4-runtime:
CXXFLAGS+=	-DMAKE_KOLAB_LIB

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

post-patch:
# Remove utils, installs nothing, but fails without BUILD_TESTS
	${REINPLACE_CMD} -e '/add_subdirectory(utils)/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
