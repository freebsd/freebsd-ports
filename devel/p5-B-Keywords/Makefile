# New ports collection makefile for:	p5-B-Keywords
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	B-Keywords
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	m@absolight.net
COMMENT=	Lists of reserved barewords and symbol names

PERL_CONFIGURE=	yes

MAN3=		B::Keywords.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use warnings|use 5.006/;' \
		 ${WRKSRC}/lib/B/Keywords.pm
.endif

.include <bsd.port.post.mk>
