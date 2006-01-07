# New ports collection makefile for:	bmp-modplug
# Date created:		2 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	modplug
PORTVERSION=	2.0.5
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

MAINTAINER=	infofarmer@gmail.com
COMMENT=	A modplug-based plugin for beep-media-player

LIB_DEPENDS?=	beep.2:${PORTSDIR}/multimedia/beep-media-player
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug

USE_BZIP2=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
PLUGDIR?=	lib/bmp/Input
PLIST_FILES=	${PLUGDIR}/libmodplugbmp.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugbmp/.libs/libmodplugbmp.so ${PREFIX}/${PLUGDIR}/

.include <bsd.port.mk>
