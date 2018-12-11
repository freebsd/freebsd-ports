# Created by: Kiyoshi Matsui <kmatsui@t3.rim.or.jp>
# $FreeBSD$

PORTNAME=	mcpp
PORTVERSION=	2.7.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V.${PORTVERSION}

MAINTAINER=	kmatsui@t3.rim.or.jp
COMMENT=	Alternative C/C++ preprocessor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mcpplib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
