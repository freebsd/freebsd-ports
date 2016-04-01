# $FreeBSD$

PORTNAME=	feedgnuplot
PORTVERSION=	1.37
CATEGORIES=	graphics perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DK/DKOGAN/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	General purpose pipe-oriented plotting tool

LICENSE=	ART10 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-String-ShellQuote>=0.50:textproc/p5-String-ShellQuote \
		p5-IPC-Run>=0:devel/p5-IPC-Run
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		gnuplot:math/gnuplot

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/feedgnuplot ${SITE_MAN1}/feedgnuplot.1.gz

.include <bsd.port.mk>
