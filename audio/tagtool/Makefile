PORTNAME=	tagtool
PORTVERSION=	0.12.3
PORTREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME MP3/Ogg file tagger
WWW=		http://pwp.netcabo.pt/paol/tagtool/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware and obsolete, doesn't properly support ID3v2 tagging
EXPIRATION_DATE=2023-03-31

LIB_DEPENDS=	libgnuregex.so.6:devel/libgnuregex \
		libid3.so:audio/id3lib \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang gettext gmake gnome localbase:ldflags \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	intlhack libglade2
GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread -logg -lm

.include <bsd.port.mk>
