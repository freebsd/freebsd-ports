# New ports collection makefile for:	pxtools
# Date created:				27 November 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pxtools
PORTVERSION=	0.0.19
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://jan.kneschke.de/projects/pxtools/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of tools to work with Paradox databases

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
