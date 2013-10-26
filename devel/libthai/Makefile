# Created by: Thawatchai Piyawat <piyawat@usablelabs.com>
# $FreeBSD$

PORTNAME=	libthai
PORTVERSION=	0.1.19
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thai language support library

LICENSE=	LGPL21

LIB_DEPENDS=	libdatrie.so:${PORTSDIR}/devel/libdatrie

USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=	gmake pathfix pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen-doc

.include <bsd.port.mk>
