# New ports collection makefile for:	libexplain
# Date created:				19 May 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libexplain
PORTVERSION=	0.46
DISTVERSIONSUFFIX=	.D001
CATEGORIES=	devel
MASTER_SITES=	http://libexplain.sourceforge.net/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library which may be used to explain Unix and Linux system call errors

LICENSE=	LGPL3

RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof

USE_AUTOTOOLS=	libtool
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>
.include "Makefile.man"

.include <bsd.port.post.mk>
