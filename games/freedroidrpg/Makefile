# New ports collection makefile for:	freedroidrpg
# Date created:			18 Jul 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	freedroidrpg
PORTVERSION=	0.9.13.r2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freedroid
DISTNAME=	${PORTNAME}-0.9.13-rc2

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Modification of the classical Freedroid engine into an RPG

USE_XLIB=	yes
USE_BZIP2=	yes
USE_SDL=	mixer image net sdl
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

CONFIGURE_ARGS=	--program-transform-name=

MAN6=		freedroidRPG.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile (missing fenv.h)"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#-lSDL # #' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
