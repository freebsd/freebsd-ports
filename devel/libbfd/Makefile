# New ports collection makefile for:	libbfd
# Date created:		26 Feb 2004
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libbfd
PORTVERSION=	2.19.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@freebsd.org
COMMENT=	Universal BFD library from GNU binutils

BUILD_DEPENDS=  ${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty

CONFLICTS=	mingw-binutils-[0-9]* binutils-[0-9]*

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/bfd

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-install-libbfd \
		--enable-commonbfdlib \
		--disable-nls \
		--without-pic \
		--enable-targets=all \
		--disable-werror
INFO=		bfd

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
ARCH=		x86_64
.endif

.include <bsd.port.post.mk>
