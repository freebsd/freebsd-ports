PORTNAME=	surge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
CATEGORIES=	ftp
PKGNAMESUFFIX=	-download-manager

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TUI download manager for power users
WWW=		https://surgedm.github.io/ \
		https://github.com/SurgeDM/Surge

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

GO_MODULE=	github.com/SurgeDM/Surge

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
