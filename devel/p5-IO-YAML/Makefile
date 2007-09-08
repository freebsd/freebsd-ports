# New ports collection makefile for:	p5-IO-YAML
# Date created:		2006-08-17
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IO-YAML
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write YAML streams incrementally

RUN_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN3=		IO::YAML.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
RUN_DEPENDS+=	${SITE_PERL}/Errno.pm:${PORTSDIR}/devel/p5-Errno
.endif

.include <bsd.port.post.mk>
