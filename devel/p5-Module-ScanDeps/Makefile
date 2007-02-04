# New ports collection makefile for:	devel/p5-Module-ScanDeps
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-ScanDeps
PORTVERSION=	0.72
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Recursively scan Perl code for dependencies

PERL_CONFIGURE=	yes

MAN1=		scandeps.pl.1
MAN3=		Module::ScanDeps.3 Module::ScanDeps::DataFeed.3

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/perl|${PERL}|' ${WRKSRC}/script/scandeps.pl \
		${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

# workaround
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or above. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
