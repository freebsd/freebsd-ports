# New ports collection makefile for:	p5-Class-DBI-SAK
# Date created:	   22 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-SAK
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Class::DBI Swiss Army Knife (SAK)

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/mixin.pm:${PORTSDIR}/devel/p5-mixin
RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Class/DBI/AbstractSearch.pm:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		${SITE_PERL}/Class/DBI/Pager.pm:${PORTSDIR}/databases/p5-Class-DBI-Pager

PERL_CONFIGURE=	yes

# Class::DBI::Join is no more
post-patch:
	@${PERL} -pi -e '$$_ = "" if (/Class::DBI::Join/ || /'\''Join'\''/)' \
			${WRKSRC}/Build.PL ${WRKSRC}/META.yml ${WRKSRC}/lib/Class/DBI/SAK.pm

MAN3=		Class::DBI::SAK.3

.include "../../devel/p5-Module-Build/inc.build.mk"
.include <bsd.port.mk>
