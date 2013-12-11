# Created by: Ashish SHUKLA <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	pms
PORTVERSION=	0.42
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A ncurses-based client for the Music Player Daemon

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

USES=		pkgconfig
NO_STAGE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

MAN1=	${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
