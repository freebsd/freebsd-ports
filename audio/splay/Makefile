PORTNAME=	splay
PORTVERSION=	0.9.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://splay.sourceforge.net/tgz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio player that decodes MPEG Layer 1/2/3 and WAV files
WWW=		http://splay.sourceforge.net/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

DEPRECATED=	Abandonware, no development in 20 years and uses obsolete decoding library
EXPIRATION_DATE=2023-03-31

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	mp3blaster # bin/splay

PLIST_FILES=	bin/splay man/man1/splay.1.gz

# XXX: pthread library can be used, but sound quality is buggy(?)

.include <bsd.port.mk>
