# New ports collection makefile for:	devel/p5-Sub-Exporter
# Date created:				30 Apr 2006
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Sub-Exporter
PORTVERSION=	0.952
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sub
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	A sophisticated exporter for custom-built routines

BUILD_DEPENDS=	p5-Sub-Install>=0.91:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::OptList.3 \
	Sub::Exporter.3 \
	Sub::Exporter::Tutorial.3 \
	Sub::Exporter::Util.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
