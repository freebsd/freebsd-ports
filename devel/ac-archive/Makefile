# New ports collection makefile for: ac-archive
# Date Created:	10 December 2001
# Whom:		kerion
#
# $FreeBSD$
#

PORTNAME=	ac-archive
PORTVERSION=	0.5.55
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of useful GNU autoconf macros

WANT_AUTOCONF_VER=253

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		acinclude.1

.include <bsd.port.mk>
