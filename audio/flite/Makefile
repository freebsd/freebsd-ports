# New ports collection makefile for:	flite
# Date created:				18 December 2004
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flite
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A small run-time speech synthesis engine

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

CFLAGS:=	${CFLAGS:N-O:N-O[0123456789]} -O0

.include <bsd.port.post.mk>
