PORTNAME=	zita-njbridge
DISTVERSION=	0.4.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line client to transmit audio over a local IP network
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		libzita-resampler.so:audio/zita-resampler

USES=		gmake localbase:ldflags tar:bzip2
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	source

MAKE_ARGS=	MANDIR=${PREFIX}/man/man1

PLIST_FILES=	bin/zita-j2n \
		bin/zita-n2j \
		man/man1/zita-j2n.1.gz \
		man/man1/zita-n2j.1.gz \
		man/man1/zita-njbridge.1.gz

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/zita-j2n \
		${STAGEDIR}${PREFIX}/bin/zita-n2j

.include <bsd.port.mk>
