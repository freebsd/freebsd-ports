PORTNAME=	amass
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.1
PORTREVISION=	8
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-depth DNS enumeration
WWW=		https://owasp.org/www-project-amass/ \
		https://github.com/owasp-amass/amass

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

LIB_DEPENDS=	libpostal.so:misc/libpostal

USES=		go:1.24+,modules pkgconfig

GO_MODULE=	github.com/owasp-amass/amass/v5
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
