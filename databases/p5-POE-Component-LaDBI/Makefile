# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-LaDBI
PORTVERSION=	1.2.1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for asynchronous non-blocking DBI calls in POE

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch

post-extract:
	${RM} ${WRKSRC}/*.pl

post-patch:
	@${PERL} -pi -e 's!(?=read_answer_yes\()!0 and !;' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
