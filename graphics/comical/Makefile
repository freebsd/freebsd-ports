# Created by: John McAree <john@mcaree.org>
# $FreeBSD$

PORTNAME=	comical
PORTVERSION=	0.8
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sequential image viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libminizip.so:archivers/minizip \
		libunrar.so.5:archivers/libunrar5

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-Wno-unused-local-typedef"

USES=		gmake
USE_WX=		2.8+

MAKE_ENV=	WX_CONFIG=${WX_CONFIG}
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

DESKTOP_ENTRIES="Comical" \
		"Comic Book Viewer" \
		"${PORTNAME}.png" \
		"${PORTNAME}" \
		"Graphics;Viewer;" \
		false

ICONS=		comical.png comical.xpm
PLIST_FILES=	bin/comical \
		share/pixmaps/comical.png \
		share/pixmaps/comical.xpm

# 'make makepatch' doesn't like dirs with spaces
pre-patch:
	@${MV} ${WRKSRC}/Comical\ Icons ${WRKSRC}/ComicalIcons

post-install:
	cd ${WRKSRC}/ComicalIcons && \
		${INSTALL_DATA} ${ICONS} ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
