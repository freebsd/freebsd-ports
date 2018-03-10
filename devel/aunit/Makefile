# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aunit
PORTVERSION=	2017
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	aunit-gpl-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada unit testing framework

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada gmake

post-patch:
	${REINPLACE_CMD} -e 's|LIBDIR|MYLIBDIR|' \
		${WRKSRC}/lib/gnat/aunit_shared.gpr

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/gnat/manifests

.include <bsd.port.mk>
