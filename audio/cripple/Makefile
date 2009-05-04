# New ports collection makefile for:	cripple
# Date created:		2007-10-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cripple
PORTVERSION=	0.06b
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.vortex.prodigynet.co.uk/${PORTNAME}/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Command line CD ripper/encoder wrapper with cddb support

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_CDRTOOLS=	yes
MAKE_JOBS_SAFE=	yes

LIB_DEPENDS+=	cdio.8:${PORTSDIR}/sysutils/libcdio
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame\
		cdparanoia:${PORTSDIR}/audio/cdparanoia

MAN1=		cripple.1

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
