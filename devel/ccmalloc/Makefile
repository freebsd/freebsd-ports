# New ports collection makefile for:	oaf
# Date created:				1st June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ccmalloc
PORTVERSION=	0.3.9
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.ethz.ch/personal/biere/projects/ccmalloc/

MAINTAINER=	jure@kom.org
COMMENT=	C/C++ memory profiler and memory leak tracer

USE_PERL5=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}

CC=		gcc -g -Wall
CXX=		g++

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 500000
EXTRA_PATCHES=	${FILESDIR}/patch5-configure
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
