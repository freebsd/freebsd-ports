# New ports collection makefile for:   gmfsk
# Date created:                29th May 2003
# Whom:                        Carl Makin <carl@stagecraft.cx>
#
# $FreeBSD$
#

PORTNAME=	gmfsk
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	comms audio
MASTER_SITES=	http://hes.iki.fi/pub/ham/unix/linux/hfmodems/

MAINTAINER=	carl@stagecraft.cx
COMMENT=	The Gnome MFSK terminal program

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

GNU_CONFIGURE=		yes
# This is pure evil but it looks like autoconf 2.53 has a bug in linking the
# preprocessor include tests.  This is a work around.
CONFIGURE_ARGS=		LDFLAGS="-L${LOCALBASE}/lib"
# There is a bug in the code that causes the compile to fail if -O is not set.
CFLAGS+=		-O -I${LOCALBASE}/include
USE_GMAKE=		yes
USE_AUTOCONF_VER=	253
USE_GNOME=		libgnomeui

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
