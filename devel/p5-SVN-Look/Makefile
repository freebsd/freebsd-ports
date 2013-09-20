# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Look
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Caching wrapper around the svnlook command

BUILD_DEPENDS=	subversion>=1.7.0:${PORTSDIR}/devel/subversion \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	subversion>=1.7.0:${PORTSDIR}/devel/subversion \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools

USES=		perl5
USE_PERL5=	configure

MAN3=		SVN::Look.3

NO_STAGE=	yes
.include <bsd.port.mk>
