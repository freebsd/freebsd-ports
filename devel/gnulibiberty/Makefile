# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnulibiberty
PORTVERSION=	2.19.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Miscellaneous GNU functions

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

USES=		gmake tar:bzip2

CONFIGURE_ARGS=	--enable-install-libiberty
GNU_CONFIGURE=	yes

CONFLICTS=	freelibiberty-[0-9]*

.include <bsd.port.mk>
