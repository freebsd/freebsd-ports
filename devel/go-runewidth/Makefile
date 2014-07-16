# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	runewidth
PORTVERSION=	0.0.0.20140715
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Go library to get the fixed width of a character or string

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	mattn
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	36f63b8

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
