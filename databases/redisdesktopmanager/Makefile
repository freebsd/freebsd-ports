# $FreeBSD$

PORTNAME=	redisdesktopmanager
PORTVERSION=	0.9.3
CATEGORIES=	databases

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Redis DB management tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		dos2unix kde:5 qmake ssl
DOS2UNIX_FILES=	3rdparty/3rdparty.pri
USE_GL=		gl
USE_GITHUB=	yes
BUILD_WRKSRC=	${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/bin/freebsd/release
PLIST_FILES=	bin/rdm \
		share/pixmaps/rdm.png
DESKTOP_ENTRIES=	"Redis Desktop Manager" "Redis Desktop Manager" "rdm.png" "rdm" "Development;" ""
GH_TUPLE=	\
		uglide:RedisDesktopManager:${PORTVERSION}:DEFAULT/RedisDesktopManager-${PORTVERSION} \
		benlau:asyncfuture:4579d53:asyncfuture/3rdparty/asyncfuture \
		RedisDesktop:CrashReporter:3455308:crashreporter/3rdparty/crashreporter \
		easylogging:easyloggingpp:f926802:easylogging/3rdparty/easyloggingpp \
		uglide:qredisclient:34f1c5a:qredisclient/3rdparty/qredisclient \
		sijk:qt-unix-signals:d6a1d12:qtunixsignals/3rdparty/qt-unix-signals \
		redis:hiredis:53c3243:hiredis/3rdparty/qredisclient/3rdparty/hiredis
USE_QT5=	buildtools_build charts concurrent core gui network qmake_build qml quick widgets

post-patch:
	@${REINPLACE_CMD} 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/src/version.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/pixmaps
	cd ${INSTALL_WRKSRC} ; \
	${STRIP_CMD} rdm ; \
	${INSTALL_PROGRAM} rdm ${STAGEDIR}${PREFIX}/bin/rdm
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources/rdm.png ${STAGEDIR}${PREFIX}/share/pixmaps/rdm.png

.include <bsd.port.mk>
