# New ports collection makefile for:	devel/p5-Module-ScanDeps
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-ScanDeps
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AU/AUTRIJUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Recursively scan Perl code for dependencies

PERL_CONFIGURE=	yes

MAN1=		scandeps.pl.1
MAN3=		Module::ScanDeps.3 Module::ScanDeps::DataFeed.3

pre-install:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/perl|${PERL}|' ${WRKSRC}/script/scandeps.pl

.include <bsd.port.mk>
