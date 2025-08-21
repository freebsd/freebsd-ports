PORTNAME=	qownnotes
PORTVERSION=	25.8.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/pbek/QOwnNotes/releases/download/v${PORTVERSION}/

MAINTAINER=	stobbsm@gmail.com
COMMENT=	Markdown note taking program with cloud integration
WWW=		https://www.qownnotes.org/

LICENSE=	GPLv2

RUN_DEPENDS=	git:devel/git

USES=		gl pkgconfig tar:xz xorg
USE_GL=		gl
USE_XORG=	x11

FLAVORS=	qt5 qt6

.if ${FLAVOR:U} == qt6
LIB_DEPENDS=	libbotan-3.so:security/botan3
CMAKE_ON=	BUILD_WITH_SYSTEM_BOTAN QON_QT6_BUILD
USES+=		cmake qt:6
USE_QT=		tools:build base declarative svg websockets
USE_XORG+=	ice sm xext
PKGNAMESUFFIX=	-${FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e '/QON_QM_FILES/s,QOwnNotes,${_QT_RELNAME},' \
		${WRKSRC}/CMakeLists.txt
.else
USES+=		gmake qmake qt:5
USE_QT=		buildtools:build linguisttools:build sql-sqlite3:run \
		concurrent core declarative gui network printsupport \
		sql svg websockets widgets x11extras xml
.endif

.include <bsd.port.mk>
