# New ports collection makefile for:    gnustep-make
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-make
PORTVERSION=	1.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/ \
		http://archive.progeny.com/gnustep/%SUBDIR%/ \
		ftp://ftp.easynet.nl/mirror/GNUstep/%SUBDIR%/
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep makefile package

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c" \
		CFLAGS="${CFLAGS} -D_THREAD_SAFE"
CONFIGURE_TARGET=
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

post-configure:
	${MV} ${WRKSRC}/config.make ${WRKSRC}/config.make.sed
	${SED} -e "s|\(objc_threaded:=\).*|\1 ${PTHREAD_LIBS}|" \
		< ${WRKSRC}/config.make.sed > ${WRKSRC}/config.make

.include <bsd.port.post.mk>
