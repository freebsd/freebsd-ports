# New ports collection makefile for: mpio-driver
# Date created:        19 Jun 2003
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=		mpio-driver
PORTVERSION=		0.2
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.gascom.ru/pub/patches/
DISTFILES=		urio.c.diff_1
EXTRACT_ONLY=

MAINTAINER=		asa@gascom.ru
COMMENT=		Digit@lway MPIO MP3 player device driver KMOD

NO_PACKAGE=		should be recompiled for a particular FreeBSD kernel

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
IGNORE=		This port only works for FreeBSD 4.x
.endif

post-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} /usr/src/sys/dev/usb/urio.c ${WRKSRC}

pre-patch:
	@${CP} ${MASTERDIR}/files/Makefile ${WRKSRC}
	@cd ${WRKSRC} && ${PATCH} < ${DISTDIR}/urio.c.diff_1

post-install:
	${INSTALL_SCRIPT} ${MASTERDIR}/files/mpio-driver.sh.sample ${PREFIX}/etc/rc.d
	@cd /dev && sh MAKEDEV urio0

.include <bsd.port.post.mk>
