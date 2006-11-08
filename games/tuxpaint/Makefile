# New ports collection makefile for:	tuxpaint
# Date created:				14 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	0.9.16
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Drawing program designed for young children

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_SDL=	image mixer sdl ttf

MAN1=		tuxpaint.1 tuxpaint-import.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs wide character string functions in libc
.endif

post-patch:
# Documentation.
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-doc\([^:]\)|\1|' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>
