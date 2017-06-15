# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	styx
PORTVERSION=	1.6.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.speculate.de/styx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scanner/parser generator

USES=		autoreconf gmake iconv libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	EXAMPLES DOCS

.include <bsd.port.mk>
