PORTNAME=	surge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	ftp
PKGNAMESUFFIX=	-download-manager

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TUI download manager for power users
WWW=		https://surgedm.github.io/ \
		https://github.com/SurgeDM/Surge

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:1.25+,modules

GO_MODULE=	github.com/SurgeDM/Surge

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
