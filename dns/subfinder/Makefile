# $FreeBSD$

PORTNAME=	subfinder
DISTVERSION=	1.2-6
DISTVERSIONSUFFIX=	-g357c340
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Subdomain discovery tool that discovers valid subdomains for websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_TUPLE=	subfinder:urlx:8e731c8:urlx/vendor/github.com/subfinder/urlx \
		bogdanovich:dns_resolver:a8e42bc:dns_resolver/vendor/github.com/bogdanovich/dns_resolver \
		miekg:dns:ccd41ff:dns/vendor/github.com/miekg/dns
GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
