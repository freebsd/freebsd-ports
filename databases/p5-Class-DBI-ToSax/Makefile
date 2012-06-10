# New ports collection makefile for:	p5-Class-DBI-ToSax
# Date created:	   22 july 2003
# Whom:		   Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-ToSax
PORTVERSION=	0.10
CATEGORIES=	databases textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension to Class::DBI for sqlite

RUN_DEPENDS=	p5-Ima-DBI>=0:${PORTSDIR}/databases/p5-Ima-DBI \
		p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-NEXT>=0:${PORTSDIR}/devel/p5-NEXT
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::ToSax.3

.include <bsd.port.mk>
