PORTNAME=	mpg321
PORTVERSION=	0.2.10
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Command-line MP3 player, compatible with mpg123
WWW=		https://mpg321.sourceforge.net/

LIB_DEPENDS=	libao.so:audio/libao \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad

USES=		cpe

CPE_VENDOR=	mpg321_project
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-mpg123-symlink
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mpg321 share/man/man1/mpg321.1.gz

OPTIONS_DEFINE=	SCROBBLER
SCROBBLER_DESC=	Last.fm Audioscrobbler support

SCROBBLER_RUN_DEPENDS=	scrobbler-helper:audio/p5-Audio-Scrobbler
SCROBBLER_PATCHFILES=	mpg321-0.2.10-scrobbler-01.patch:scrobbler
SCROBBLER_PATCH_SITES=	http://people.FreeBSD.org/~roam/ports/audio/:scrobbler \
		http://devel.ringlet.net/audio/mpg321-scrobbler/:scrobbler

.include <bsd.port.mk>
