# New ports collection makefile for:	gnurobots
# Date created:				22 Sept 2000
# Whom:					Aaron VonderHaar <avh4@usa.net>
#
# $FreeBSD$
#

PORTNAME=	gnurobots
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world

LIB_DEPENDS=	guile.19:${PORTSDIR}/lang/guile

USE_XORG=	x11 xpm
USE_GNOME=	gnometarget glib20
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README THANKS doc/Robots-HOWTO doc/contrib
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
