# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiredis
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalistic C client library for the Redis database

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	redis
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	9be3a07

USES=		gmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e '/^REAL_/s/ \$$(ARCH)//' \
		-e 's|\$$(INSTALL_LIBRARY_PATH)/\$$(PKGCONF_PATH)|\$$(DESTDIR)\$$(PREFIX)/libdata/\$$(PKGCONF_PATH)|' \
		${WRKSRC}/Makefile

post-build:
	@${STRIP_CMD} ${WRKSRC}/libhiredis.so

.include <bsd.port.mk>
