# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsplot
PORTVERSION=	1.7.4
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	A perl script which analyses the history of a CVS-managed project

RUN_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote \
		gnuplot:${PORTSDIR}/math/gnuplot

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/cvsplot
USES=		shebangfix
SHEBANG_FILES=	cvsplot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsplot.pl ${PREFIX}/bin/cvsplot

.include <bsd.port.mk>
