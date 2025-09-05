PORTNAME=	amass
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-depth DNS enumeration
WWW=		https://owasp.org/www-project-amass/ \
		https://github.com/owasp-amass/amass

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: cgo_specific.go:100:2: type [1073741824]*_Ctype_char larger than address space

LIB_DEPENDS=	libpostal.so:misc/libpostal

USES=		go:1.24,modules pkgconfig

GO_MODULE=	github.com/owasp-amass/amass/v5
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
