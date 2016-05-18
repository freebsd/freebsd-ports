# $FreeBSD$

PORTNAME=	duktape
PORTVERSION=	1.5.0
CATEGORIES=	lang devel
MASTER_SITES=	http://duktape.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable Javascript engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		libedit tar:xz

MAKEFILE=	Makefile.cmdline
ALL_TARGET=	duk

PLIST_FILES=	bin/duk

post-patch:
	@${REINPLACE_CMD} -e "/history\.h/d ; s,readline/,editline/,g " \
		${WRKSRC}/examples/cmdline/duk_cmdline.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
