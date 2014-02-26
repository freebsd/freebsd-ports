# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-sql-driver
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://github.com/${PORTNAME}/mysql/archive/v${PORTVERSION}.tar.gz?dummy=/ \
    		http://mirrors.rit.edu/zi/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Lightweight and fast MySQL driver for go

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION}
GH_PROJECT=	mysql
GH_COMMIT=	9a7aa36

GO_PKGNAME=	github.com/go-sql-driver/mysql
WRKSRC=		${WRKDIR}/mysql-${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
