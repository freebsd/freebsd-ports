# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcircllhist
PORTVERSION=	g20200417
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Circonus log-linear histogram C implementation

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	circonus-labs
GH_TAGNAME=	b7c6248

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${LN} -s libcircllhist.so.0.0.1 \
		${STAGEDIR}${PREFIX}/lib/libcircllhist.so.0

.include <bsd.port.mk>
