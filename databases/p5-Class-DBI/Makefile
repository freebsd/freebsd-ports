# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI
PORTVERSION=	3.0.17
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Database Abstraction

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-Trigger>=0:devel/p5-Class-Trigger \
		p5-Clone>=0:devel/p5-Clone \
		p5-Ima-DBI>=0:databases/p5-Ima-DBI \
		p5-UNIVERSAL-moniker>=0:devel/p5-UNIVERSAL-moniker
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
