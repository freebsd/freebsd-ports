# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	concurrencykit
PORTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	http://concurrencykit.org/releases/ \
		http://repnop.org/releases/
DISTNAME=	ck-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Lock-free data structures for high performance concurrent systems

LICENSE=	BSD

USES=		pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

post-extract:
	${REINPLACE_CMD} -e 's|PKGCONFIG_DATA=@LIBRARY@|PKGCONFIG_DATA=${PREFIX}/libdata/|g' \
	${WRKSRC}/Makefile.in

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
