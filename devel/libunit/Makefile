# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libunit
PORTVERSION=	1.21.0
MASTER_SITES?=	https://unit.nginx.org/download/
DISTNAME=	unit-${PORTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Development kit for dynamic web application server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CATEGORIES=	devel www

USES+=		compiler:c11 cpe

CPE_VENDOR=	nginx
CPE_PRODUCT=	unit

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--ld-opt="-L${LOCALBASE}/lib"

PLIST_FILES+=	include/nxt_auto_config.h \
		include/nxt_unit_field.h \
		include/nxt_unit_request.h \
		include/nxt_unit_response.h \
		include/nxt_unit_sptr.h \
		include/nxt_unit_typedefs.h \
		include/nxt_unit_websocket.h \
		include/nxt_unit.h \
		include/nxt_version.h \
		include/nxt_websocket_header.h \
		lib/libunit.a

do-build:
	@cd ${WRKSRC} && ${MAKE} build/libunit.a

do-install:
	${MAKE} -C ${WRKSRC} libunit-install DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
