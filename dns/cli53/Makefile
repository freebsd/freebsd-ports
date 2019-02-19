# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cli53
DISTVERSION=	0.8.14
CATEGORIES=	dns

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command line management of Route53 domains

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC:H:H}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	barnybug

WRKSRC_SUBDIR=	cmd/cli53
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/cli53
PLIST_FILES=	bin/cli53

post-extract:
	@${MKDIR} ${GO_WRKSRC:H:H:H}
	@${LN} -sf ${WRKSRC:H:H} ${GO_WRKSRC:H:H}

.include <bsd.port.mk>
