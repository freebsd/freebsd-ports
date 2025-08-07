PORTNAME=	go
DISTVERSION=	${GO_DEFAULT}
PORTREVISION=	11
PORTEPOCH=	2
CATEGORIES=	lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	go@FreeBSD.org
COMMENT=	Meta-port for the default version of the Go programming language
WWW=		https://golang.org

RUN_DEPENDS=	go${GO_SUFFIX}:lang/go${GO_SUFFIX}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/go bin/gofmt

GO_SUFFIX=	${GO_DEFAULT:S/.//:C/.*-devel/-devel/}

do-install:
.for f in go gofmt
	@${LN} -sf ${f}${GO_SUFFIX} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
