# Created by: Aaron VonderHaar <avh4@usa.net>
# $FreeBSD$

PORTNAME=	gnurobots
PORTVERSION=	1.2.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile

USES=		pkgconfig
USE_GNOME=	vte
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include <pty.h>||g' ${WRKSRC}/src/ui-cmdwin.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README THANKS doc/Robots-HOWTO doc/contrib
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
