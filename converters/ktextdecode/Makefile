# New ports collection makefile for:	ktextdecode
# Date created:				08.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	ktextdecode
PORTVERSION=	3.0
PORTREVISION=	7
CATEGORIES=	converters kde
MASTER_SITES=	http://osmirrors.cerias.purdue.edu/pub/FreeBSD/ports/local-distfiles/markus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The simple text conversion utility for KDE 3

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
