# New ports collection makefile for:	ifd-test
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ifd-test
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/

MAINTAINER=	bms@spc.org
COMMENT=	IFD Test Suite for PC/SC Lite

LIB_DEPENDS=    pcsclite.0:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes

NOMAN=
PLIST_FILES=	sbin/ifdtest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifdtest ${PREFIX}/sbin

.include <bsd.port.mk>
