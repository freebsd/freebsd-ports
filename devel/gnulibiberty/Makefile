PORTNAME=	gnulibiberty
PORTVERSION=	2.46.0
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
TEST_TARGET=	check

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

.include <bsd.port.mk>
