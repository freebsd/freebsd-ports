# New ports collection makefile for:   vmips
# Date created:        13 July 2004
# Whom:                brg
#
# $FreeBSD$
#

PORTNAME=	vmips
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.dgate.org/vmips/releases/vmips-${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	brg@dgate.org
COMMENT=	MIPS R3000 simulator

BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/teTeX-base

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		vmips.1 vmipstool.1
INFO=		vmips

.include <bsd.port.mk>
