PORTNAME=	puzzles
PORTVERSION=	20250714
CATEGORIES=	games
# upstream does not preserve older versions, mirroring is mandatory
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/puzzles/ \
		https://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	sgt-
DISTNAME=	${PORTNAME}-${PORTVERSION}.${COMMITHASH}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simon Tatham's Portable Puzzle Collection
WWW=		https://www.chiark.greenend.org.uk/~sgtatham/puzzles/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	halibut:textproc/halibut

USES=		cmake gnome magick:build perl5 pkgconfig
USE_PERL5=	build
CMAKE_ARGS=	-DNAME_PREFIX:STRING=sgt-

COMMITHASH=	880288c

DATADIR=	${PREFIX}/share/sgt-puzzles
PORTDATA=	*

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=GTK3

GTK_DESC=	Gtk version
GTK2_CMAKE_ON=	-DPUZZLES_GTK_VERSION=2
GTK2_USE=	GNOME=gtk20
GTK3_CMAKE_ON=	-DPUZZLES_GTK_VERSION=3
GTK3_USE=	GNOME=gtk30

maintainer-update:
	@location=$$(curl -sI ${MASTER_SITES:[1]}/puzzles.tar.gz | grep -i ^location | awk '{print $$2}'); \
		version=$$(echo $$location | tr '.-' '  ' | awk '{print $$(NF-3)}'); \
		hash=$$(echo $$location | tr '.-' '  ' | awk '{print $$(NF-2)}'); \
		sed -i '' \
			-e "s|${COMMITHASH}|$$hash|" \
			-e "s|${PORTVERSION}|$$version|" \
			${.CURDIR}/Makefile

.include <bsd.port.mk>
