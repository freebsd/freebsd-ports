# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Config
PORTVERSION=	0.0911
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for config-driven Subversion notification

RUN_DEPENDS=	${LOCALBASE}/bin/svnlook:${PORTSDIR}/devel/subversion \
		p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-YAML>=0.62:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	p5-Test-Deep>=0.1:${PORTSDIR}/devel/p5-Test-Deep \
		${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		SVN::Notify::Config.3

NO_STAGE=	yes
.include <bsd.port.mk>
