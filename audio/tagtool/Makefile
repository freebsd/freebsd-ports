PORTNAME=	tagtool
PORTVERSION=	0.12.3
PORTREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME MP3/Ogg file tagger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnuregex.so.6:devel/libgnuregex \
		libid3.so:audio/id3lib \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang gettext gmake gnome localbase:ldflags \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	intlhack libglade2
GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread -logg -lm

.include <bsd.port.mk>
