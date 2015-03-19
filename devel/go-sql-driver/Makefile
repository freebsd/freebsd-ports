# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-sql-driver
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	GHL \
    		http://mirrors.rit.edu/zi/

MAINTAINER=	lattera@gmail.com
COMMENT=	Lightweight and fast MySQL driver for go

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_PROJECT=	mysql
GH_COMMIT=	9a7aa36

GO_PKGNAME=	github.com/${PORTNAME}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
