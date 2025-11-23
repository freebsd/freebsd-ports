PORTNAME=	qownnotes
DISTVERSION=	25.9.3
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/pbek/QOwnNotes/releases/download/v${DISTVERSION}/

MAINTAINER=	stobbsm@gmail.com
COMMENT=	Markdown note taking program with cloud integration
WWW=		https://www.qownnotes.org/

LICENSE=	GPLv2

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}
qt5_PKGNAMESUFFIX=	-qt5

qt6_LIB_DEPENDS=	libbotan-3.so:security/botan3 \
			libgit2.so:devel/libgit2
qt5_RUN_DEPENDS=	git:devel/git

USES=		gl pkgconfig tar:xz xorg
USE_GL=		gl
USE_XORG=	x11

.if ${FLAVOR:U} == qt5
USES+=		gmake qmake qt:5
USE_QT=		buildtools:build linguisttools:build sql-sqlite3:run \
		concurrent core declarative gui network printsupport \
		sql svg websockets widgets x11extras xml
.else
USES+=		cmake qt:6
USE_QT=		tools:build base declarative svg websockets
USE_XORG+=	ice sm xext
.endif

.if ${FLAVOR:U} == qt6
CMAKE_ON=	BUILD_WITH_LIBGIT2 \
		BUILD_WITH_SYSTEM_BOTAN \
		QON_QT6_BUILD
.endif

post-patch:
	@${REINPLACE_CMD} -e '/QON_QM_FILES/s,QOwnNotes,${_QT_RELNAME},' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
