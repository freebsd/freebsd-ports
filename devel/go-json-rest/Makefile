# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-json-rest
PORTVERSION=	1.0.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GH GHC \
		http://mirrors.rit.edu/zi/

MAINTAINER=	lattera@gmail.com
COMMENT=	Quick and easy way to setup a RESTful JSON API

USE_GITHUB=	yes
GH_ACCOUNT=	ant0ine
GH_TAGNAME=	v${PORTVERSION}
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	91c5416

GO_PKGNAME=	github.com/ant0ine/go-json-rest

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GO_LIBDIR}/${GO_PKGNAME}
	@${INSTALL_DATA} ${GO_WRKDIR_PKG}/${GO_PKGNAME}/trie.a \
	    	${STAGEDIR}${PREFIX}/${GO_LIBDIR}/${GO_PKGNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
