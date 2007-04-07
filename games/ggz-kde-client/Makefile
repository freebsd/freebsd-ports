# New ports collection makefile for:	ggz-kde-client
# Date created:				Feb. 19, 2006
# Whom:					yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-kde-client
PORTVERSION=	${GGZ_VERSION}
CATEGORIES=	games

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - KDE Client

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man"
USE_GMAKE=	yes
USE_KDELIBS_VER=	3
USE_GGZ=	client

MAN6=		compcal.6 ggzap.6 keepalivecontrol.6 \
		kggz.6 kgrubby.6 shadowbridge.6

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}| ; s|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
