PORTNAME=	gnulibiberty
PORTVERSION=	2.43
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Miscellaneous GNU functions

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

USES=		gmake tar:lz

CONFIGURE_ARGS=	--enable-install-libiberty --disable-multilib
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
