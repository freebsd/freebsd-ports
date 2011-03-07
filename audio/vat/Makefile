# New ports collection makefile for:	vat
# Date created:		2 November 1996
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	vat
PORTVERSION=	4.0b2
PORTREVISION=	3
CATEGORIES=	audio mbone tk
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Visual Audio Tool - multicast audioconferencing

DEPRECATED=	Unmaintained, anachronistic, mail freebsd-ports@FreeBSD.org if interested
EXPIRATION=	2011-06-30

GSM_DIR=	${.CURDIR}/../../audio/gsm
GSM_WORK=	${WRKDIRPREFIX}${GSM_DIR}/work/gsm-1.0-pl13

# If configure is changed to look for libgsm.a in ${PREFIX}/lib, then
# we can use this first BUILD_DEPENDS and save some work.
#BUILD_DEPENDS=	${GSM_WORK}/inc/private.h:${GSM_DIR}:patch
BUILD_DEPENDS=	${GSM_WORK}/lib/libgsm.a:${GSM_DIR}:build
LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83 \
		gsm.1:${GSM_DIR}

USE_XORG=	x11
USE_AUTOTOOLS=	autoconf213
CONFIGURE_ARGS=	--with-gsm=${GSM_WORK}
INSTALL_TARGET=	install install-man
MAN1=		vat.1
PLIST_FILES=	bin/vat

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/vat

.include <bsd.port.post.mk>
