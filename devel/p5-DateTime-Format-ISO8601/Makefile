# New ports collection makefile for:	p5-DateTime-Format-ISO8601
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-ISO8601
PORTVERSION=	0.04.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Parse ISO8601 formats

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Builder.pm:${PORTSDIR}/devel/p5-DateTime-Format-Builder

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::ISO8601.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use warnings/;' \
		 ${WRKSRC}/lib/DateTime/Format/ISO8601.pm
.endif

.include <bsd.port.post.mk>
