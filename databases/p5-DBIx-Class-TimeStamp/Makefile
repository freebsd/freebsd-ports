# New ports collection makefile for:	databases/p5-DBIx-Class-TimeStamp
# Date created:				28 April 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-TimeStamp
PORTVERSION=	0.14
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	DBIx::Class extension to handle date and time based fields

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:${PORTSDIR}/databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DateTime>=0.55:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::TimeStamp.3

post-patch:
	${PERL} -pi -e '$$_="" if /auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
