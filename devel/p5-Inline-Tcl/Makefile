# New ports collection makefile for:	Inline::Tcl
# Date created:		14 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Inline-Tcl
PORTVERSION=	0.09
CATEGORIES=	devel perl5 tcl84
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Inline
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Write Perl subroutines in Tcl

BUILD_DEPENDS=	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline
LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC="-I${PREFIX}/include/tcl8.4" \
		LIBS="-L${PREFIX}/lib -R${PREFIX}/lib -ltcl84"

MAN3=		Inline::Tcl.3

post-patch:
	@${PERL} -pi -e '$$_="" if $$.>1 && $$.<100' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
