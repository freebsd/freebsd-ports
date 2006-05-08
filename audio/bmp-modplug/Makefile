# New ports collection makefile for:	bmp-modplug
# Date created:		2 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	modplug
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES?=	audio
MASTER_SITES=	ftp://ftp.dvo.ru/pub/Gentoo/distfiles/ \
		ftp://ftp.cb.spb.ru/.6/Linux-Distrib/Gentoo/distfiles/ \
		ftp://ftp.neva.ru/.6/Linux-Distrib/Gentoo/distfiles/ \
		ftp://ftp.rusnet.ru/.6/Linux-Distrib/Gentoo/distfiles/ \
		ftp://ftp.org.kemsu.ru/gentoo/distfiles/ \
		ftp://unix.miet.ru/pub/linux/gentoo/distfiles/ \
		ftp://ftp.duth.gr/pub/gentoo/distfiles/ \
		ftp://ftp.fasta.fh-dortmund.de/mirror/gentoo/distfiles/ \
		ftp://ftp.freenet.de/pub/.disk3/ftp.snt.utwente.nl/pub/os/linux/gentoo/distfiles/ \
		ftp://ftp.nerdc.ufl.edu/pub/mirrors/gentoo/distfiles/ \
		ftp://ftp.uni-kl.de/pub/linux/gentoo/distfiles/
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PORTNAME}${PKGNAMEPREFIX}2.05

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A modplug-based plugin for beep-media-player

LIB_DEPENDS?=	beep.2:${PORTSDIR}/multimedia/beep-media-player
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug

USE_BZIP2=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
PLUGDIR?=	lib/bmp/Input
PLIST_FILES=	${PLUGDIR}/libmodplugbmp.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugbmp/.libs/libmodplugbmp.so ${PREFIX}/${PLUGDIR}/

.include <bsd.port.post.mk>
