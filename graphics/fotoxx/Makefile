# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	fotoxx
PORTVERSION=	14.02.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kornelix.com/uploads/1/3/0/3/13035936/ \
		LOCAL/mandree

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application to organize and edit image collections

LICENSE=	GPLv3

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		ufraw-batch:${PORTSDIR}/graphics/ufraw \
		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool \
		dcraw:${PORTSDIR}/graphics/dcraw

USES=		gmake desktop-file-utils pkgconfig
USE_GNOME=	gtk30

ALL_TARGET=	fotoxx
INSTALL_TARGET=	install MANDIR=${PREFIX}/man/man1/

LDFLAGS+=	-O3 -g -Wall -rdynamic -lexecinfo

OPTIONS_DEFINE=	DOCS

post-patch:
	@# drop xdg-desktop-menu calls, they fail
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e '/xdg-desktop-menu/d' \
		-e '/rm -f -R/d' \
		${WRKSRC}/Makefile
	@# replace obsolete include files
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/zfuncs.h
	@# fix up icon path in XDG .desktop file
	${REINPLACE_CMD} -e 's}/usr/share/fotoxx}${DATADIR}}' \
		${WRKSRC}/desktop

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fotoxx

.include <bsd.port.pre.mk>

# These hacks are required because the nginx server at the primary
# master site and most of our fetch(1) versions do not get along well.
#   This code can be removed once r261263 has been merged from
# base/head into all ports-supported releases.
# We depend on cURL unless wget is in $LOCALPATH:
DISABLE_SIZE=	yes
.if exists(${LOCALBASE}/bin/wget) && !exists(${PREFIX}/bin/curl)
FETCH_CMD=		${LOCALBASE}/bin/wget -c -nc
.else
FETCH_DEPENDS=		curl:${PORTSDIR}/ftp/curl
FETCH_CMD=		${PREFIX}/bin/curl -OL0C -
.endif

.include <bsd.port.post.mk>
