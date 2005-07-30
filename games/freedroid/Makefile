# New ports collection makefile for: criticalmass
# Date created:		15 Sep 2003
# Whom:			benlutz@datacomm.ch
#
# $FreeBSD$
#

PORTNAME=	freedroid
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freedroid

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Freedroid is a clone of the classic game "Paradroid"

USE_XLIB=	yes
USE_SDL=	mixer image sdl
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=

MAN6=		freedroid.6

post-extract:
.for d in graphics map sound
	@${FIND} ${WRKSRC}/${d} -type f -name "Makefile*" -print0 | \
		${XARGS} -0 ${RM}
.endfor

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#-lSDL # #;' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's#$$(man_MANS) mac-osx ##;' \
				${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's#\#include \"mac-osx/getopt\.h\"##;' \
				${WRKSRC}/src/system.h

.include <bsd.port.post.mk>
