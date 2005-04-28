# New ports collection makefile for:	advancecomp
# Date created:		11 May 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	advancecomp
PORTVERSION=	1.14
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	advancemame

MAINTAINER=	sylvioc@gmail.com
COMMENT=	Recompression utilities for .ZIP, .PNG, .MNG and .GZ files

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		advdef.1 advmng.1 advpng.1 advzip.1
PLIST_FILES=	bin/advdef bin/advmng bin/advpng bin/advzip

.include <bsd.port.mk>
