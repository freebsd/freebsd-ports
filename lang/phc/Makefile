# Created by: Conor McDermottroe <ports@mcdermottroe.com>
# $FreeBSD$

PORTNAME=	phc
PORTVERSION=	0.1.7
CATEGORIES=	lang
MASTER_SITES=	http://www.phpcompiler.org/src/archive/

MAINTAINER=	eg@fbsd.lt
COMMENT=	Compiler for the PHP language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/LICENSE

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS} -fgnu89-inline"

post-patch:	.SILENT
	${REINPLACE_CMD} 's/g++/$$CXX/' \
		${WRKSRC}/phc_compile_plugin.in
	${REINPLACE_CMD} 's/insert/this->&/' \
		${WRKSRC}/lib/List.h

.include <bsd.port.mk>
