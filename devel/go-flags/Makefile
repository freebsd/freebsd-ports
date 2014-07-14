# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flags
PORTVERSION=	1.0.0.20140623
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Go command line option parser

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	jessevdk
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7047cf7

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
