# New ports collection makefile for:	devel/p5-Module-ScanDeps
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-ScanDeps
PORTVERSION=	0.75
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Recursively scan Perl code for dependencies

BUILD_DEPENDS=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build

PERL_CONFIGURE=	yes

MAN1=		scandeps.pl.1
MAN3=		Module::ScanDeps.3 Module::ScanDeps::DataFeed.3

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/perl|${PERL}|' ${WRKSRC}/script/scandeps.pl \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
