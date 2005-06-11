# New ports collection makefile for:	p5-Devel-ptkdb
# Date created:				May 9th 2002
# Whom:					Alex Kapranoff <kappa@freebsd.org.ua>
#
# $FreeBSD$
#

PORTNAME=	Devel-ptkdb
PORTVERSION=	1.1086
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua
COMMENT=	Tk debugger for Perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

PERL_CONFIGURE=	yes

MAN3=		Devel::ptkdb.3

.include <bsd.port.mk>
