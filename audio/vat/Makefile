# New ports collection makefile for:	vat
# Version required:	4.0b2
# Date created:		2 November 1996
# Whom:			fenner
#
# $Id: Makefile,v 1.4 1997/09/11 03:54:43 fenner Exp $
#

DISTNAME=	vat-4.0b2
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

GSM_DIR=	${PORTSDIR}/audio/gsm
GSM_WORK=	${GSM_DIR}/work/gsm-1.0-pl10

# If configure is changed to look for libgsm.a in ${PREFIX}/lib, then
# we can use this first BUILD_DEPENDS and save some work.
#BUILD_DEPENDS=	${GSM_WORK}/inc/private.h:${GSM_DIR}:patch
BUILD_DEPENDS=	${GSM_WORK}/lib/libgsm.a:${GSM_DIR}:build
LIB_DEPENDS=	tk80:${PORTSDIR}/x11/tk80 \
		gsm:${GSM_DIR}

USE_X11=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-gsm=${GSM_WORK}
INSTALL_TARGET=	install install-man
MAN1=		vat.1

post-install:
	strip ${PREFIX}/bin/vat

.include <bsd.port.mk>
