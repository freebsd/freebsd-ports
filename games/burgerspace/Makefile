# New ports collection makefile for:	burgerspace
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	burgerspace
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://sites.netscape.net/sarrazip/

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	gengameng.2:${PORTSDIR}/devel/gengameng \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lgnugetopt"
CONFIGURE_ARGS+=	--with-gengameng-prefix="${X11BASE}"

MAN6=	burgerspace.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/burgerspace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/burgerspace.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
