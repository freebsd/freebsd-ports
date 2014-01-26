# Created by: Ashish SHUKLA <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	pms
PORTVERSION=	0.42
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	A ncurses-based client for the Music Player Daemon

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/pms.1.gz

CONFIGURE_ENV=	STRIP=${STRIP_CMD}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
