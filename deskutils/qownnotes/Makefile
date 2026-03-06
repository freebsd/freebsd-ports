PORTNAME=	qownnotes
DISTVERSION=	26.3.3
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/pbek/QOwnNotes/releases/download/v${DISTVERSION}/

MAINTAINER=	stobbsm@gmail.com
COMMENT=	Markdown note taking program with cloud integration
WWW=		https://www.qownnotes.org/

LICENSE=	GPLv2

USES=		gl pkgconfig tar:xz xorg
USE_GL=		gl
USE_XORG=	x11

FLAVORS=	qt6 qt5

.if ${FLAVOR:U} == qt5
RUN_DEPENDS=	git:devel/git
USES+=		gmake qmake qt:5
USE_QT=		buildtools:build linguisttools:build sql-sqlite3:run \
		concurrent core declarative gui network printsupport \
		sql svg websockets widgets x11extras xml
PKGNAMESUFFIX=	-${FLAVOR}
.else
LIB_DEPENDS=	libbotan-3.so:security/botan3 \
		libgit2.so:devel/libgit2
CMAKE_ON=	BUILD_WITH_LIBGIT2 BUILD_WITH_SYSTEM_BOTAN QON_QT6_BUILD
USES+=		cmake qt:6
USE_QT=		tools:build base declarative svg websockets
USE_XORG+=	ice sm xext

post-patch:
	@${REINPLACE_CMD} -e '/QON_QM_FILES/s,QOwnNotes,${_QT_RELNAME},' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
