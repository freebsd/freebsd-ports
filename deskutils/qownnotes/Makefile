PORTNAME=	qownnotes
PORTVERSION=	24.8.6
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/pbek/QOwnNotes/releases/download/v${PORTVERSION}/

MAINTAINER=	stobbsm@gmail.com
COMMENT=	Markdown note taking program with cloud integration
WWW=		https://www.qownnotes.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libbotan-2.so:security/botan2
RUN_DEPENDS=	git:devel/git

USES=		gl gmake pkgconfig qmake qt:5 tar:xz xorg
USE_GL=		gl
USE_QT=		buildtools:build linguisttools:build sql-sqlite3:run \
		concurrent core declarative gui network printsupport \
		sql svg websockets widgets x11extras xml
USE_XORG=	x11

QMAKE_ARGS=	USE_SYSTEM_BOTAN=1

.include <bsd.port.mk>
