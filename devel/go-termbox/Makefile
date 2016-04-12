# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termbox
PORTVERSION=	0.0.0.20160123
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Pure Go termbox implementation

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-runewidth.a:devel/go-runewidth

USE_GITHUB=	yes
GH_ACCOUNT=	nsf
GH_PROJECT=	${PORTNAME}-go
GH_TAGNAME=	362329b

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
