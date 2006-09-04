# New ports collection makefile for:	zoom
# Date created:				May 07 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	zoom
PORTVERSION=	1.0.2a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.demon.co.uk/unix/${PORTNAME}/
DISTNAME=	zoom-1.0.2alpha1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Z-Interpreter for X with full V6 support

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		expat.6:${PORTSDIR}/textproc/expat2

USE_PERL5=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
