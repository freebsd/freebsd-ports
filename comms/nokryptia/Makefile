# New ports collection makefile for:	nokryptia
# Date created:				1 July 2004
# Whom:					Aleksander Fafula <alex@fafula.com>
#
# $FreeBSD$
#

PORTNAME=	nokryptia
PORTVERSION=	1.3
CATEGORIES=	comms
MASTER_SITES=	http://tuxmobil.org/software/nokryptia/

MAINTAINER=	alex@fafula.com
COMMENT=	A tool for fast loading mp3s into Nokia 5510

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

MAN1=		nokryptia.1
PLIST_FILES=	bin/nokryptia

.include <bsd.port.mk>
