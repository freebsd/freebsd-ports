PORTNAME=	vorbisgain
PORTVERSION=	0.37
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	gamato@users.sf.net
COMMENT=	Calculates the perceived sound level of an Ogg Vorbis file

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		localbase:ldflags
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vorbisgain \
		man/man1/vorbisgain.1.gz

OPTIONS_DEFINE=	RECURSIVE

RECURSIVE_DESC=	recursive processing and pattern matching
RECURSIVE_CONFIGURE_ENABLE=	recursive

.include <bsd.port.mk>
