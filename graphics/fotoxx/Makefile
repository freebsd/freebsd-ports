# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	fotoxx
PORTVERSION=	11.03
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://kornelix.squarespace.com/downloads/ \
		http://www.rodperson.com/DL/

MAINTAINER=	rodperson@rodperson.com
COMMENT=	Application to organize and edit image collections

BROKEN=		Does not fetch

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		ufraw-batch:${PORTSDIR}/graphics/ufraw \
		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool

USE_GNOME=	gtk20
USE_GMAKE=	yes
MANCOMPRESSED=	yes
MAN1=		fotoxx.1

ALL_TARGET=	fotoxx
INSTALL_TARGET=	install manpage

LDFLAGS+=	-O3 -g -Wall -rdynamic -lexecinfo

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
			${WRKSRC}/Makefile \
			${WRKSRC}/dependencies.sh

.include <bsd.port.mk>
