# New ports collection makefile for:	devel/p5-Class-Accessor-Chained
# Date created:				03 November 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor-Chained
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	make chained accessors

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Class::Accessor::Chained.3 \
		Class::Accessor::Chained::Fast.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	${PERL} -pi -e 's/our ([^ ]+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/lib/Class/Accessor/Chained.pm
.endif

.include <bsd.port.post.mk>
