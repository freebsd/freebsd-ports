# ex:ts=8
# Ports collection makefile for:	cvsplot
# Date created:			May 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsplot
PORTVERSION=	1.6.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A perl script which analyses the history of a CVS-managed project

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		gnuplot:${PORTSDIR}/math/gnuplot

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,^#!/usr/bin/perl -w,#!/usr/bin/env perl -w,g" ${WRKSRC}/cvsplot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsplot.pl ${PREFIX}/bin/cvsplot

.include <bsd.port.mk>
