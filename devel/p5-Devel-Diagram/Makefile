# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Devel-Diagram
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Discover the classes of an arbitrary suite of Perl modules

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
