# Created by: Horance Chou <horance@freedom.ie.cycu.edu.tw>

PORTNAME=	libffi
PORTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}
PKGNAMESUFFIX=	321

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foreign Function Interface (stripped down compat version)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_riscv64=		fails to configure: libffi has not been ported to riscv64-portbld-freebsd13.0.

USES=		cpe libtool
USE_LDCONFIG=	${PREFIX}/lib/compat
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/compat \
		--disable-static
CPE_VENDOR=	libffi_project

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
