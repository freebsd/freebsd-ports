# New ports collection makefile for:	mpio-driver
# Date created:				19 Jun 2003
# Whom:					Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	mpiosh
PORTVERSION=	0.7.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mpio
DISTNAME=	mpio-${PORTVERSION}

MAINTAINER=	asa@gascom.ru
COMMENT=	Digit@lway MPIO MP3 player tool

RUN_DEPENDS=	${MODULES}/mpio.ko:${PORTSDIR}/audio/mpio-driver
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

MODULES?=	/modules

USE_LIBTOOL=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
IGNORE=		This port only works for FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
