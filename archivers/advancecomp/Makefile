# New ports collection makefile for:	advancecomp
# Date created:		11 May 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	advancecomp
PORTVERSION=	1.11
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	advancemame

MAINTAINER=	hsn@netmag.cz
COMMENT=	Recompression utilities for .ZIP, .PNG, .MNG and .GZ files

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETOPT_LONG=yes
USE_GMAKE=	yes

PLIST_FILES=	bin/advzip bin/advpng bin/advmng bin/advdef
MAN1=		advzip.1 advpng.1 advmng.1 advdef.1

.include <bsd.port.mk>
