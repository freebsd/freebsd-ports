# New ports collection makefile for:	Devel-Diagram
# Date created:	   25 January 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-Diagram
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Discover the classes of an arbitrary suite of Perl modules

PERL_CONFIGURE=	yes

MAN3=		Devel::Diagram.3 Devel::Diagram::Render::UXF20.3

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//'

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
