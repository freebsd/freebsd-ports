# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	adms
PORTVERSION=	2.3.5
CATEGORIES=	cad
MASTER_SITES=	SF/mot-${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Model generator for SPICE simulators

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ax_cv_c_compiler_vendor=gnu
CONFIGURE_ARGS=	--disable-silent-rules
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
