# ex:ts=8
# Ports collection makefile for:	cvsplot
# Date created:			May 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsplot
PORTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	SF

MAINTAINER=	erik@smluc.org
COMMENT=	A perl script which analyses the history of a CVS-managed project

RUN_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote \
		gnuplot:${PORTSDIR}/math/gnuplot

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/cvsplot

post-patch:
	@${PERL} -pi -e "s,^#!/usr/bin/perl -w,#!/usr/bin/env perl -w,g" ${WRKSRC}/cvsplot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsplot.pl ${PREFIX}/bin/cvsplot

.include <bsd.port.mk>
