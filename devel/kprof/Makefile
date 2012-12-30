# ex:ts=8
# Ports collection makefile for:	kprof
# Date Created:			 	24 December 2001
# Whom:					Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	kprof
PORTVERSION=	1.3.1
PORTREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A profiling tool for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	KDB2HTML=${PREFIX}/bin/kdb2html
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.mk>
