# Created by: Luca Pizzamiglio <luca.pizzamiglio@gmail.com>
# $FreeBSD$

PORTNAME=	breakpad
DISTVERSION=	g20170811
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Client/server based crash-reporting system

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf compiler:c++11-lib
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME= 38cbbfed71efcb28931b5e4a83e3c0d4661f1548

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/src/third_party/lss
	@${CP} ${FILESDIR}/linux_syscall_support.h ${WRKSRC}/src/third_party/lss

.include <bsd.port.mk>
