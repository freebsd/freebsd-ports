# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	adms
PORTVERSION=	2.3.2
CATEGORIES=	cad
MASTER_SITES=	SF/mot-${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Model generator for SPICE simulators

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gmake libtool pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
