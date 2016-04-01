# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI-ToSax
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	databases textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension to Class::DBI for sqlite

RUN_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer \
		p5-NEXT>=0:devel/p5-NEXT
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
