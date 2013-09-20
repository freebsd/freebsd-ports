# Created by: Mitchell Smith <mjs@bur.st>
# $FreeBSD$

PORTNAME=	frontbase
PORTVERSION=	0.0.1
CATEGORIES=	databases ruby
MASTER_SITES+=	http://www.frontbase.com/download/Ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	ruby-frontbase-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjs@bur.st
COMMENT=	Ruby interface to the FrontBase db engine

BUILD_DEPENDS+=	${LOCALBASE}/lib/libFBCAccess.a:${PORTSDIR}/databases/frontbase
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-frontbase

CONFIGURE_WRKSRC=	${WRKSRC}
BUILD_WRKSRC=		${WRKSRC}
INSTALL_WRKSRC=		${WRKSRC}
INSTALL_TARGET=	site-install

NO_STAGE=	yes
.include <bsd.port.mk>
