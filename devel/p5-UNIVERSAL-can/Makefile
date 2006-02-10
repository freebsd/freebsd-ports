# New ports collection makefile for:	p5-UNIVERSAL-can
# Date Created:				16 Nov, 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	UNIVERSAL-can
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CH/CHROMATIC
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Hack around people calling UNIVERSAL::can() as a function

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-Simple>=0.60:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Warn>=0.08:${PORTSDIR}/devel/p5-Test-Warn
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		UNIVERSAL::can.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6 or later. Install lang/perl5 or lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
