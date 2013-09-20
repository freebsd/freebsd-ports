# Created by: Aleksander Fafula <alex@fafula.com>
# $FreeBSD$

PORTNAME=	nokryptia
PORTVERSION=	1.3
CATEGORIES=	comms
MASTER_SITES=	http://tuxmobil.org/software/nokryptia/ \
		http://www.bsdguru.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for fast loading mp3s into Nokia 5510

LIB_DEPENDS=	id3-3.8:${PORTSDIR}/audio/id3lib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		nokryptia.1
PLIST_FILES=	bin/nokryptia

NO_STAGE=	yes
.include <bsd.port.mk>
