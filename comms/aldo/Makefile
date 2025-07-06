PORTNAME=	aldo
DISTVERSION=	0.7.8
CATEGORIES=	comms hamradio
MASTER_SITES=	https://git.savannah.nongnu.org/cgit/${PORTNAME}.git/snapshot/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Morse code training program
WWW=		https://www.nongnu.org/aldo/ \
		https://savannah.nongnu.org/projects/aldo/

LICENSE=	GPLv2+

LIB_DEPENDS=	libao.so:audio/libao

USES=		autoreconf compiler:c++0x localbase

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/aldo \
		share/man/man1/aldo.1.gz

.include <bsd.port.mk>
