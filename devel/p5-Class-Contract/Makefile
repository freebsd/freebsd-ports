# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Class-Contract
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Design-by-Contract OO in Perl

USES=		perl5 dos2unix
USE_PERL5=	configure
PLIST_SUB+=	EXAMPLESDIR="share/examples/${PORTNAME}"

pre-configure:
	${MKDIR} ${WRKSRC}/examples
	${MV} ${WRKSRC}/demo.pl ${WRKSRC}/examples

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
