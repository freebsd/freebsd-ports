# New ports collection makefile for:	xzx
# Date created:         13 Nov 1997
# Whom:                 Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	xzx
PORTVERSION=	4.4
CATEGORIES=	emulators
# I don't maintain this port anymore, but I'm happy to track the distfiles, as
# it's difficult to fetch(1) them from the WWW site. If you are updating this
# port, shoot me an email if you want me to add the new distfile to
# MASTER_SITE_LOCAL  -- adamw@
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw
DISTNAME=	${PORTNAME}-pro-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ZX Spectrum (48K/128K/+3) Emulator for X11

# xmkmf is used in configure script; USE_IMAKE makes the build unhappy
BUILD_DEPENDS=	xmkmf:${X_IMAKE_PORT}

USE_MOTIF=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

# License forbids redistribution
RESTRICTED=	Redistribution forbidden by license

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss

MAN1=		xzx.1

# Prevent configure from trying to run auto* since it's not needed and will
# error if auto* < 2.54
post-configure:
		@${REINPLACE_CMD} 's@autoheader@${TRUE}@g' ${WRKSRC}/Makefile
		@${REINPLACE_CMD} 's@autoconf@${TRUE}@g' ${WRKSRC}/Makefile
		@${ECHO_CMD} "${TRUE}" > ${WRKSRC}/missing

.include <bsd.port.mk>
