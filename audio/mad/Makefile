# New ports collection makefile for:  mad
# Date created:        18 November 2000
# Whom:                Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	mad
PORTVERSION=	0.14.2b
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	jason@mastaler.com

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

WANT_ESOUND=	yes

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure libmad/configure libid3tag/configure
CONFIGURE_ARGS=	--enable-shared \
		--disable-debugging \
		--enable-sso \
		--enable-accuracy
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		abxtest.1 madplay.1

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
.else
CONFIGURE_ARGS+= --without-esd
.endif

.include <bsd.port.post.mk>
