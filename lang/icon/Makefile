# New ports collection makefile for:    icon
# Date created:         05 April 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon
PORTVERSION=	9.3.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.arizona.edu/icon/packages/unix/
DISTNAME=	unix
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

ONLY_FOR_ARCHS=	i386

DIST_SUBDIR=	icon
NO_WRKSUBDIR=	true
ALL_TARGET=	Icon Icon-iconc

do-configure:
	(cd ${WRKSRC}; ${MAKE} Configure name=intel_freebsd)

.include <bsd.port.mk>
