# New ports collection makefile for:	p5-Tcl
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tcl
PORTVERSION=	0.98
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Tcl extension module for Perl5

USE_TCL=	84+
PERL_CONFIGURE=	yes

MAN3=		Tcl.3

.include <bsd.port.pre.mk>

CONFIGURE_ARGS= --tclsh ${TCLSH}

.include <bsd.port.post.mk>
