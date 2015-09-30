# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libnvpair
PORTVERSION=	1.0.2
CATEGORIES=	databases devel

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Illumos name-value pair library

LICENSE=	CDDL

GH_ACCOUNT=	jrmarino
USE_GITHUB=	yes

MAKE_ARGS=	LIBDIR=${PREFIX}/lib

post-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} libnvpair.h nvpair.h \
		nvpair_type_compat.h ${STAGEDIR}${PREFIX}/include/)

.include <bsd.port.mk>
