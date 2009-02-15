# New ports collection makefile for:	p5-github_creator
# Date created:		2008-11-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	github_creator
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BD/BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create a Github repository for your Perl module

RUN_DEPENDS=	p5-Config-IniFiles>0:${PORTSDIR}/devel/p5-Config-IniFiles	\
		p5-File-Find-Closures>0:${PORTSDIR}/devel/p5-File-Find-Closures	\
		p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl	\
		p5-WWW-Mechanize>0:${PORTSDIR}/www/p5-WWW-Mechanize	\
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN1=		github_creator.1

.include <bsd.port.mk>
