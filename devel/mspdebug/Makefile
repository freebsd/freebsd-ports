# Created by: Peter Jeremy <peterjeremy@acm.org>
# $FreeBSD$

PORTNAME=	mspdebug
PORTVERSION=	0.25.20180301
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	peterjeremy@acm.org
COMMENT=	Debugger for use with MSP 430 MCUs

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	dlbeer
GH_TAGNAME=	7c41acd

OPTIONS_DEFINE=		READLINE LIBMSP430
OPTIONS_DEFAULT=	READLINE LIBMSP430
LIBMSP430_DESC=		Use TI libmsp430 USB driver

READLINE_USES=		readline ncurses pkgconfig
READLINE_MAKE_ARGS_OFF=	WITHOUT_READLINE=1

LIBMSP430_LIB_DEPENDS=	libmsp430.so:devel/msp430-debug-stack

USES=		gmake

PLIST_FILES=	bin/mspdebug \
		man/man1/mspdebug.1.gz \
		share/mspdebug/ti_3410.fw.ihex \
		share/mspdebug/ti_3410.fw.txt \
		share/doc/mspdebug/EmbeddedMode.txt \
		share/doc/mspdebug/README

post-patch:
	@${REINPLACE_CMD} -e 's|-ltermcap||' ${WRKSRC}/Makefile

.include <bsd.port.mk>
