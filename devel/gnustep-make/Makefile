# New ports collection makefile for:    gnustep-make
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-make
PORTVERSION=	1.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep makefile package

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c" \
		CFLAGS="${CFLAGS}"
CONFIGURE_TARGET=
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=	--with-thread-lib="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-config-file=${PREFIX}/GNUstep.conf

.if defined(GNUSTEP_WITH_BASE_GCC)
GNUSTEP_WITHOUT_LIBOBJC=	yes
.endif

post-install:
	${LN} -s Library/Makefiles ${PREFIX}/System/

.include <bsd.port.mk>
