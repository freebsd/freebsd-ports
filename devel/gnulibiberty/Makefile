# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnulibiberty
PORTVERSION=	2.19.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Miscellaneous GNU functions

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-install-libiberty
GNU_CONFIGURE=	yes

CONFLICTS=	freelibiberty-[0-9]*

NO_STAGE=	yes
.include <bsd.port.mk>
