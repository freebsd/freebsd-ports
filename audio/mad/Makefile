# New ports collection makefile for:  mad
# Date created:        18 November 2000
# Whom:                Jason R. Mastaler <jason-freebsd@mastaler.com> et al.
#
# $FreeBSD$
#

PORTNAME=	mad
PORTVERSION=	0.13.0b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	jason-freebsd@mastaler.com

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libmad/configure
CONFIGURE_ARGS=	--disable-debugging --enable-sso --enable-accuracy
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		abxtest.1 madplay.1

.include <bsd.port.mk>
