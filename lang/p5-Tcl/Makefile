# New ports collection makefile for:	p5-Tcl
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tcl
PORTVERSION=	1.02
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VKON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Tcl extension module for Perl5

CONFIGURE_ARGS=	--nousestubs --tclsh ${TCLSH}
PERL_CONFIGURE=	yes
USE_TCL=	84+

MAN3=		Tcl.3

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 \{} \;
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} 0644 \{} \;

.include <bsd.port.mk>
