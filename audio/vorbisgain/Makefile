PORTNAME=	vorbisgain
PORTVERSION=	0.37
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	gamato@users.sf.net
COMMENT=	Calculates the perceived sound level of an Ogg Vorbis file
WWW=		https://sjeng.org/vorbisgain.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		localbase:ldflags
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/vorbisgain \
		share/man/man1/vorbisgain.1.gz

OPTIONS_DEFINE=	RECURSIVE

RECURSIVE_DESC=	recursive processing and pattern matching
RECURSIVE_CONFIGURE_ENABLE=	recursive

.include <bsd.port.mk>
