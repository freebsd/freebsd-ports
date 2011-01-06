# New ports collection makefile for:   instead
# Date created:            19 Dec 2010
# Whom:                neuroworker@gmail.com
#
# $FreeBSD$

PORTNAME=	instead
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://209.44.102.205/FreeBSD/distfiles/
DISTNAME=	instead_${PORTVERSION}

MAINTAINER=	neuroworker@gmail.com
COMMENT=	Simple Text Adventure, The Interpreter

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gtk20
USE_LUA=	5.1
USE_SDL=	sdl image ttf mixer
USE_ICONV=	yes

CONFIGURE_SCRIPT=	configure.sh

WRKSRC=		${WRKDIR}/instead-${PORTVERSION}
MAN6=		instead.6

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|port_install_prefix|${PREFIX}|' ${WRKSRC}/configure.sh
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/INSTALL.*DOCPATH/ d' ${WRKSRC}/doc/Makefile
.endif

.include <bsd.port.mk>
