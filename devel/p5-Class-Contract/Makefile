# New ports collection makefile for:	Class::Contract
# Date created:		5 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Contract
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Design-by-Contract OO in Perl

PERL_CONFIGURE=	yes
PLIST_SUB+=	EXAMPLESDIR="share/examples/${PORTNAME}"

MAN3=		Class::Contract.3 Class::Contract::Production.3

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.p[lm]" | \
		${XARGS} ${PERL} -pi -e 's/\x0d//g;'

pre-configure:
	${MKDIR} ${WRKSRC}/examples
	${MV} ${WRKSRC}/demo.pl ${WRKSRC}/examples

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
