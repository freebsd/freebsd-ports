# New ports collection makefile for:    gnustep-make
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-make
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	1.9.1
PORTREVISION=	1
.else
PORTVERSION=	1.8.0
PORTREVISION=	2
.endif
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep makefile package

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c" \
		CFLAGS="${CFLAGS}"
CONFIGURE_TARGET=
USE_GMAKE=	yes
USE_GNUSTEP=	yes
GNUSTEP_WITH_BASE_GCC=		yes
GNUSTEP_WITHOUT_LIBOBJC=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CFLAGS+=	${PTHREAD_CFLAGS}

post-configure:
	${MV} ${WRKSRC}/config.make ${WRKSRC}/config.make.sed
	${SED} -e "s|\(objc_threaded:=\).*|\1${PTHREAD_LIBS}|" \
		< ${WRKSRC}/config.make.sed > ${WRKSRC}/config.make

.include <bsd.port.mk>
