# Created by: Anthony Ginepro <anthony.ginepro@laposte.net>
# $FreeBSD$
#    $MCom: ports/audio/tagtool/Makefile,v 1.1 2006/09/30 01:15:37 ahze Exp $

PORTNAME=	tagtool
PORTVERSION=	0.12.3
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME MP3/Ogg file tagger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libid3.so:audio/id3lib \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang gettext gmake localbase:ldflags pathfix \
		pkgconfig tar:bzip2
USE_GNOME=	intlhack libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

LDFLAGS+=	-lpthread -logg -lm

.include <bsd.port.mk>
