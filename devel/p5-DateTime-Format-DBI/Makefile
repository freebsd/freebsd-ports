# New ports collection makefile for:	p5-DateTime-Format-DBI
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-DBI
PORTVERSION=	0.03.2
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find a parser class for a database connection

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::DBI.3

post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/lib/DateTime/Format/DBI.pm

.include <bsd.port.mk>
