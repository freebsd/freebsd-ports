# New ports collection makefile for:	gecode
# Date created:				24 January 2011
# Whom:					roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gecode
PORTVERSION=	3.4.2
CATEGORIES=	devel
MASTER_SITES=	http://www.gecode.org/download/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

BUILD_DEPENDS=	bison>=2.3:${PORTSDIR}/devel/bison \
		flex>=2.5.35:${PORTSDIR}/textproc/flex

LICENSE=	MIT
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

MAKE_JOBS_UNSAFE=	yes
PATCH_STRIP=	-p1

CONFIGURE_ARGS+=\
		--disable-static \
		--enable-shared \
		--disable-doc-dot \
		--disable-doc-tagfile \
		--disable-doc-chm \
		--disable-qt \
		--disable-gist \
		--enable-driver \
		--enable-graph \
		--enable-flatzinc \
		--enable-sheduling \
		--disable-examples \
		--enable-minimodel \
		--enable-search

.include <bsd.port.mk>
