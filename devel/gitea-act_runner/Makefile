PORTNAME=	act_runner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.11
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	gitea-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Act runner is a runner for Gitea based on Gitea fork of act
WWW=		https://gitea.com/gitea/act_runner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:1.23,modules
GO_MODULE=	gitea.com/gitea/act_runner

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
