# $FreeBSD$

PORTNAME=	wdns
PORTVERSION=	0.10.0
CATEGORIES=	dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Low-level DNS library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake libtool pathfix pkgconfig python:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		EXAMPLES
PORTEXAMPLES=		*

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
