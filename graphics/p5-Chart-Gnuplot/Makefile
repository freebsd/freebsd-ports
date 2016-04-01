# $FreeBSD$

PORTNAME=	Chart-Gnuplot
PORTVERSION=	0.23
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	koue@chaosophia.net
COMMENT=	Perl module to plot graphs using GNUPLOT on the fly

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/Chart/Gnuplot.pm \
		%%SITE_PERL%%/Chart/Gnuplot/Util.pm \
		%%PERL5_MAN3%%/Chart::Gnuplot.3.gz
post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
