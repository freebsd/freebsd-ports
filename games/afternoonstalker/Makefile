# New ports collection makefile for:	afternoonstalker
# Date created:			Feb 15, 2003
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	afternoonstalker
PORTVERSION=	1.1.4
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A clone of the 1981 Night Stalker video game

LIB_DEPENDS=	flatzebra-0.1.2:${PORTSDIR}/devel/flatzebra

USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		afternoonstalker.6
PORTDOCS=	AUTHORS COPYING INSTALL NEWS README THANKS TODO

post-patch:
	@${REINPLACE_CMD} -e 's|^pkgsounddir =.*|pkgsounddir = ${DATADIR}/sounds|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am/s|install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
