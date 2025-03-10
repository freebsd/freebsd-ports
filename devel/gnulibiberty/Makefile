PORTNAME=	gnulibiberty
PORTVERSION=	2.44
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Miscellaneous GNU functions

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		gmake tar:lz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-install-libiberty --disable-multilib

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

.include <bsd.port.mk>
