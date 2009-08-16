# New ports collection makefile for:	databases/p5-DBIx-Class-HTML-FormFu
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-HTML-FormFu
PORTVERSION=	0.01005
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fill a HTML::FormFu form from the database and vice-versa

RUN_DEPENDS=	p5-HTML-FormFu>=0:${PORTSDIR}/www/p5-HTML-FormFu \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

DEPRECATED=	This module is obsoleted by www/p5-HTML-FormFu-Model-DBIC

MAN3=	DBIx::Class::HTML::FormFu.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^warn/ .. /^END/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
