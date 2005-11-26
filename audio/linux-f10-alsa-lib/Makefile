# New ports collection makefile for:	linux-alsa-lib
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	alsa-lib
DISTVERSION=	1.0.6-8
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	updates/3/${LINUX_ARCH}/
DISTNAME=	${PORTNAME}-${DISTVERSION}.FC3

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	The Advanced Linux Sound Architecture libraries

ONLY_FOR_ARCHS=	i386 amd64
INSTALLS_LINUX_SHLIB=	yes
DESCR=		${PKGDIR}/pkg-descr

.include "${.CURDIR}/../../audio/linux-openal/bsd.linux.mk"
