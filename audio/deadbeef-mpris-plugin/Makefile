# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-mpris-plugin
PORTVERSION=	2.1.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	MPRIS plugin for DeaDBeeF music player

LICENSE=	GPLv3

BROKEN=		does not work with recent versions of glib and/or DeaDBeeF
DEPRECATED=	Abandonware; use `audio/deadbeef-mpris2-plugin' instead
EXPIRATION_DATE=	2016-05-16

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USES=		pkgconfig libtool
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/deadbeef-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/Makefile.in \
		${WRKSRC}/test/Makefile.in

.include <bsd.port.mk>
