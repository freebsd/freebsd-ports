# Created by: Joerg Wunsch <joerg@FreeBSD.org>

PORTNAME=	gnulibiberty
PORTVERSION=	2.33.1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Miscellaneous GNU functions

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

USES=		gmake tar:xz

CONFIGURE_ARGS=	--enable-install-libiberty
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
