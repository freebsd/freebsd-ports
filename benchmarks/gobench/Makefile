# $FreeBSD$

PORTNAME=	gobench
PORTVERSION=	1.1
CATEGORIES=	benchmarks net

MAINTAINER=	guy.tabrar@me.com
COMMENT=	HTTP benchmarking tool written in Go

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	go:lang/go \
		go-fasthttp>=0:www/go-fasthttp

USE_GITHUB=	yes
GH_ACCOUNT=	tabrarg

NO_ARCH=        yes
NO_BUILD=       yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/gobench

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gobench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gobench.go ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gobench.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
