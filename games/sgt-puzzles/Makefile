PORTNAME=	puzzles
PORTVERSION=	20210526
CATEGORIES=	games
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/puzzles/ \
		https://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	sgt-
DISTNAME=	${PORTNAME}-${PORTVERSION}.${COMMITHASH}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simon Tatham's Portable Puzzle Collection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

COMMITHASH=	8f3413c

BUILD_DEPENDS=	convert:graphics/ImageMagick6-nox11

USES=		cmake gnome perl5 pkgconfig
USE_PERL5=	build
CMAKE_ARGS=	-DNAME_PREFIX:STRING=sgt-

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=GTK3

GTK_DESC=	Gtk version
GTK2_CMAKE_ON=	-DPUZZLES_GTK_VERSION=2
GTK2_USE=	GNOME=gtk20
GTK3_CMAKE_ON=	-DPUZZLES_GTK_VERSION=3
GTK3_USE=	GNOME=gtk30

.include <bsd.port.mk>
