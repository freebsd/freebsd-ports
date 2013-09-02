# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	statgrab
PORTVERSION=	0.1
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A set of Ruby bindings for libstatgrab

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USES=		pkgconfig

INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.mkdn ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
