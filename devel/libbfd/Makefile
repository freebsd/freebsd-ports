# New ports collection makefile for:	libbfd
# Date created:		26 Feb 2004
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libbfd
PORTVERSION=	2.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@freebsd.org
COMMENT=	Universal BFD library from GNU binutils

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/bfd

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-install-libbfd \
		--enable-commonbfdlib \
		--disable-nls \
		--enable-targets=all
USE_LIBTOOL=	yes

INFO=		bfd

.include <bsd.port.mk>
