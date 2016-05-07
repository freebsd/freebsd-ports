# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	DBIx-Recordset
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for abstraction and simplification of database access

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-configure:
# bad DBIx::Intrors.3
		@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 -lax/;' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
