# New ports collection makefile for:	jbootstrap
# Date created:				7 July 2005
# Whom:					<glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jbootstrap
PORTVERSION=	1.0
CATEGORIES=	java
MASTER_SITES=	# http://www.eyesbeyond.com/freebsddom/java/jbootstrap.html

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java bootstrap tools

USE_PERL5_RUN=	yes
MAKE_FLAGS+=	BINDIR=${PREFIX}/${PORTNAME}/bin \
		LIBEXECDIR=${PREFIX}/${PORTNAME}/libexec
.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-doc
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		"This port requires perl 5.8 or above."
.endif

.if !exists(${DISTDIR}/${DISTFILE}) && !defined(PACKAGE_BUILDING)
IGNORE= Please fetch ${DISTFILE} from http://www.eyesbeyond.com/freebsddom/java/jbootstrap.html and place it in ${DISTDIR}
.endif

.include <bsd.port.post.mk>
