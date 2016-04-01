# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	libisofs
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Libburnia ISO9660 filesystem creation library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libburn.so:devel/libburn

GNU_CONFIGURE=	yes
USES=		iconv libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

.include <bsd.port.mk>
