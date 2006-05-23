# New ports collection makefile for:	p5-Tcl
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tcl
PORTVERSION=	0.89
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Tcl extension module for Perl5

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--tclsh tclsh8.4

MAN3=		Tcl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
