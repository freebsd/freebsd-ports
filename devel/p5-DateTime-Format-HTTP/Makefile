# New ports collection makefile for:	p5-DateTime-Format-HTTP
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-HTTP
PORTVERSION=	0.35.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	HTTP date conversion routines

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::HTTP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif
.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use warnings/;' \
		 ${WRKSRC}/lib/DateTime/Format/HTTP.pm
.endif

.include <bsd.port.post.mk>
