# New ports collection makefile for:	vat
# Version required:	4.0b2
# Date created:		2 November 1996
# Whom:			fenner
#
# $Id: Makefile,v 1.1.1.1 1996/11/10 21:11:47 fenner Exp $
#

DISTNAME=	vat-4.0b2
CATEGORIES=	mbone
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

GSM_DIR=	${PORTSDIR}/audio/gsm

DEPENDS=	${GSM_DIR}
LIB_DEPENDS=	tk41:${PORTSDIR}/x11/tk41 \
		gsm:${GSM_DIR}

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gsm=${GSM_DIR}/work/gsm-1.0-pl10
INSTALL_TARGET=	install install-man
MAN1=		vat.1

post-install:
	strip ${PREFIX}/bin/vat

.include <bsd.port.mk>
