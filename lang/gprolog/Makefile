# New ports collection makefile for:   gprolog
# Date created:        30 June 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	gprolog
PORTVERSION=	1.2.16
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	A free Prolog compiler

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}"

PLIST_SUB+=	GPROLOG_VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/EnginePl/machine.c

.include <bsd.port.mk>
