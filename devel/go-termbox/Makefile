# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termbox
PORTVERSION=	0.0.0.20140625
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Pure Go termbox implementation

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nsf
GH_PROJECT=	${PORTNAME}-go
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	81b415f

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
