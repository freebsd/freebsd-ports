# New ports collection makefile for:	asmix
# Date created:		1 January 2003
# Whom:			mtm@identd.net
#
# $FreeBSD$
#

PORTNAME=	asmix
PORTVERSION=	1.5
CATEGORIES=	audio afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asmix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Volume control dock-app for the AfterStep Window Manager

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1x
PLIST_FILES=	bin/asmix

post-patch:
.for file in asmix.c configure autoconf/config.h.in
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g ; \
		 s|MACHINE_SOUNDCARD|SYS_SOUNDCARD|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
