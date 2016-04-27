# $FreeBSD$

PORTNAME=	bdb1
PORTVERSION=	0.2.5
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to Berkeley DB revision 1.8x with full feature support

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

USE_RUBY=	yes
USES=		execinfo gem

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.2
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-ext_bdb1_recnum.c
.endif

.include <bsd.port.post.mk>
