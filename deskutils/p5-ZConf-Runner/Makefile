# New ports collection makefile for:	p5-ZConf-Runner
# Date created:		2009-01-14
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Runner
PORTVERSION=	0.0.0
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Run a file using a choosen methode, desktop entry or mimetype

RUN_DEPENDS=	${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${SITE_PERL}/File/MimeInfo/Applications.pm:${PORTSDIR}/devel/p5-File-MimeInfo

PERL_CONFIGURE=	yes

MAN3=		ZConf::Runner.3

.include <bsd.port.mk>
