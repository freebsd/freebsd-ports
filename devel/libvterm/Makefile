PORTNAME=	libvterm
PORTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	https://www.leonerd.org.uk/code/libvterm/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Implementation of a VT220/xterm/ECMA-48 terminal emulator
WWW=		https://www.leonerd.org.uk/code/libvterm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe gmake libtool:build pathfix perl5
CPE_VENDOR=	leonerd
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
USE_PERL5=	build test
TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/unterm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-ctrl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-dump
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvterm.so

.include <bsd.port.mk>
