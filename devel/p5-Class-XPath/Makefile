# New ports collection makefile for:	Class-XPath
# Date created:		Mon Mar 29 19:33:38 CST 2004
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Class-XPath
PORTVERSION=	1.4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Base class to add xpath matching to object trees

PERL_CONFIGURE=	yes

MAN3=		Class::XPath.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -i -pe '$$_ = "" if /use 5.006/;' \
			-e 's/^our (\S+)/use vars qw($$1); $$1/;' \
			-e 's/(use|no) warnings[^;]*;//' \
			${WRKSRC}/Makefile.PL ${WRKSRC}/XPath.pm
.endif

.include <bsd.port.post.mk>
