# New ports collection makefile for:	p5-Smart-Comments
# Date created:				24 May 2005
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Smart-Comments
PORTVERSION=	1.0.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CH/CHORNY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Comments that do more than just sit there

BUILD_DEPENDS=	p5-Filter-Simple>=0.80:${PORTSDIR}/textproc/p5-Filter-Simple \
		p5-Text-Balanced>=2.0:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Smart::Comments.3

.include <bsd.port.mk>
