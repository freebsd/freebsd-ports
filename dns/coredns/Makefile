PORTNAME=	coredns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.3
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DNS server that chains plugins
WWW=		https://coredns.io \
		https://github.com/coredns/coredns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*$$ # otherwise it picks up the deleted tag v011

post-install:
.for n in 1 5 7
	${INSTALL_MAN} ${WRKSRC}/man/*.${n} ${STAGEDIR}${PREFIX}/share/man/man${n}
.endfor

.include <bsd.port.mk>
