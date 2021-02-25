# $FreeBSD$

PORTNAME=	coredns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.3
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DNS server that chains plugins

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*$$ # otherwise it picks up the deleted tag v011

.include <bsd.port.mk>
