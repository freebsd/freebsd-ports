# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	rlog
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Flexible message logging facility for C++

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	anastmag

OPTIONS_DEFINE=	DOCS

USES=		gmake pathfix libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
