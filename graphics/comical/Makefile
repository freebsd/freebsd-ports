# Created by: John McAree <john@mcaree.org>
# $FreeBSD$

PORTNAME=	comical
PORTVERSION=	0.8
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sequential image viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libminizip.so:archivers/minizip \
		libunrar.so.5:archivers/libunrar5

USES=		compiler:c++11-lang gmake
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

.include <bsd.port.pre.mk>

# 'make makepatch' doesn't like dirs with spaces
pre-patch:
	@${MV} ${WRKSRC}/Comical\ Icons ${WRKSRC}/ComicalIcons

.if ${CHOSEN_COMPILER_TYPE} == gcc
pre-configure:
	${REINPLACE_CMD} -e 's|-Wno-unused-local-typedef||' ${WRKSRC}/src/Makefile
.endif

post-install:
	cd ${WRKSRC}/ComicalIcons && \
		${INSTALL_DATA} ${ICONS} ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.post.mk>
