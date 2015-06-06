# $FreeBSD$

PORTNAME=	duktape
PORTVERSION=	1.2.2
CATEGORIES=	lang devel
MASTER_SITES=	http://duktape.org/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Embeddable Javascript engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	tar:xz

LIB_DEPENDS=	libedit.so.0:${PORTSDIR}/devel/libedit
MAKEFILE=	Makefile.cmdline
ALL_TARGET=	#

PLIST_FILES=	bin/duk

# for libedit
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ARGS=	CC="${CC}"

post-patch:
	@${REINPLACE_CMD} -e "/history\.h/d ; s,readline/,editline/,g " \
		${WRKSRC}/examples/cmdline/duk_cmdline.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
