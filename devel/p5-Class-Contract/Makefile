# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Class-Contract
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Design-by-Contract OO in Perl

PERL_CONFIGURE=	yes
USE_DOS2UNIX=	yes
PLIST_SUB+=	EXAMPLESDIR="share/examples/${PORTNAME}"

MAN3=		Class::Contract.3 Class::Contract::Production.3

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
