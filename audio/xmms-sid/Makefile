# New ports collection makefile for:	xmms-sid
# Date created:				9 Sep 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-sid
PORTVERSION=	0.7.4
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	dyeske@yahoo.com

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS = -O2 -W -Wall|CFLAGS = @CFLAGS@ |; \
		s|-lstdc++||; \
		s|^LIBS = -lsidplay|LIBS = -lsidplay -lstdc++|' \
		${BUILD_WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
