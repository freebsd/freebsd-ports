PORTNAME=	amass
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
PORTREVISION=	13
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-depth DNS enumeration
WWW=		https://owasp.org/www-project-amass/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/OWASP/Amass/v4
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
