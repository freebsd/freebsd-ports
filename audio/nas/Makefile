# New ports collection makefile for:	nas (formerly netaudio)
# Date created:		03 Nov 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	nas
PORTVERSION=	1.6
CATEGORIES=	audio
MASTER_SITES=	http://nas.codebrilliance.com/nas/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Audio System

USE_REINPLACE=	yes
USE_IMAKE=	yes
ALL_TARGET=	World
# no need to "xmkmf -a" and create the Makefiles twice -- see above
XMKMF=		xmkmf
INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

post-install:
	@${SED} -e 's:/usr/X11R6:${PREFIX}:g' ${PKGMESSAGE}

.include "Makefile.man"
.include <bsd.port.mk>
