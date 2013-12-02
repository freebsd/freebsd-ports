# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtap
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/nik
DISTNAME=	tap-${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Library implementing the Test Anything Protocol

LICENSE=	BSD

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-build:
	@${ECHO_MSG} "If you have Perl and Test::Harness installed you can run the test suite"
	@${ECHO_MSG} "for libtap by running"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    make check"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "or"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    prove -r"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtap.so

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
