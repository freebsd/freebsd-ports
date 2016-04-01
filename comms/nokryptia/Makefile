# Created by: Aleksander Fafula <alex@fafula.com>
# $FreeBSD$

PORTNAME=	nokryptia
PORTVERSION=	1.3
CATEGORIES=	comms
MASTER_SITES=	http://tuxmobil.org/software/nokryptia/ \
		http://www.bsdguru.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for fast loading mp3s into Nokia 5510

LIB_DEPENDS=	libid3.so:audio/id3lib

GNU_CONFIGURE=	yes
USES=	tar:bzip2
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/nokryptia man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
