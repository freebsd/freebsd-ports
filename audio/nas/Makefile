# New ports collection makefile for:	nas (formerly netaudio)
# Date created:		03 Nov 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	nas
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://radscan.com/nas/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
ALL_TARGET=	World
# no need to "xmkmf -a" and create the Makefiles twice -- see above
XMKMF=		xmkmf
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.man"

post-patch:
	@find ${WRKSRC} -name '*.[ch]' | xargs \
		${PERL} -pi -e "s|<malloc.h>|<stdlib.h>|g"

post-install:
	@${SED} -e 's:/usr/X11R6:${PREFIX}:g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
