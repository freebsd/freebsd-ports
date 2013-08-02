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

MAN3=		Devel::Diagram.3 Devel::Diagram::Render::UXF20.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
