# New ports collection makefile for:	pxtools
# Date created:				27 November 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pxtools
PORTVERSION=	0.0.19
CATEGORIES=	databases
MASTER_SITES=	http://jan.kneschke.de/projects/pxtools/download/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
