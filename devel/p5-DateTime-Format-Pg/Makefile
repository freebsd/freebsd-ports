# New ports collection makefile for:	p5-DateTime-Format-Pg
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Pg
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Parse and format PostgreSQL dates and times

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/TimeZone.pm:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		${SITE_PERL}/DateTime/Format/Builder.pm:${PORTSDIR}/devel/p5-DateTime-Format-Builder
BUILD_DEPENDS=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Pg.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\@ISA)/use vars qw($$1); $$1/;' \
		${WRKSRC}/lib/DateTime/Format/Pg.pm
.endif

.include <bsd.port.post.mk>
