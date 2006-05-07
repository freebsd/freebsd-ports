# New ports collection makefile for:	koth
# Date created:			15 Oct 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	koth
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=games/multiplayer

MAINTAINER=	tlp@liquidx.org
COMMENT=	Multiplayer tank artillery game similar to Scorched Earth

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/kclever-ai bin/kmoron-ai bin/koth bin/koths
MAN6=		kclever-ai.6 kmoron-ai.6 koth.6 koths.6

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DGG_NEED_OLD_INTTYPES" LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lggi|-lggi ${PTHREAD_LIBS}|' ${WRKSRC}/configure

.include <bsd.port.mk>
