# New ports collection makefile for:	devel/p5-Algorithm-Accounting
# Date created:				25 Oct 2004
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Accounting
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GU/GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Generate accounting statistic for general logs

BUILD_DEPENDS=	${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy \
		${SITE_PERL}/Perl6/Form.pm:${PORTSDIR}/devel/p5-Perl6-Form \
		${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${SITE_PERL}/Array/Compare.pm:${PORTSDIR}/misc/p5-Array-Compare \
		${SITE_PERL}/Array/Iterator/Reusable.pm:${PORTSDIR}/devel/p5-Array-Iterator \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/Imager/Graph/Pie.pm:${PORTSDIR}/graphics/p5-Imager-Graph \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Algorithm::Accounting.3 \
		Algorithm::Accounting::Report.3 \
		Algorithm::Accounting::Report::Imager.3 \
		Algorithm::Accounting::Report::GDGraph.3 \
		Algorithm::Accounting::Report::Text.3

.include <bsd.port.mk>
