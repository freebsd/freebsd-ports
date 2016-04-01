# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsplot
PORTVERSION=	1.7.4
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Perl script which analyses the history of a CVS-managed project

RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote \
		gnuplot:math/gnuplot

NO_BUILD=	yes
PLIST_FILES=	bin/cvsplot
USES=		shebangfix perl5
SHEBANG_FILES=	cvsplot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsplot.pl ${STAGEDIR}${PREFIX}/bin/cvsplot

.include <bsd.port.mk>
