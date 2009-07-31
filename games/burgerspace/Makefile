# New ports collection makefile for:	burgerspace
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	burgerspace
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A BurgerTime clone

LIB_DEPENDS=	gengameng.4:${PORTSDIR}/devel/gengameng \
		flatzebra-0.1.2:${PORTSDIR}/devel/flatzebra

GNU_CONFIGURE=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CCONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		burgerspace.6
PORTDOCS=	*

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
