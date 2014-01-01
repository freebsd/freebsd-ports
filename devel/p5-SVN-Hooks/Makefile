# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Hooks
PORTVERSION=	1.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Framework for implementing Subversion hooks

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Util>=0:${PORTSDIR}/devel/p5-Data-Util \
		p5-Email-Send>=0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple>=2.100_1:${PORTSDIR}/mail/p5-Email-Simple \
		p5-SVN-Look>=0:${PORTSDIR}/devel/p5-SVN-Look \
		p5-SVN-Notify>=0:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-JIRA-Client>=0:${PORTSDIR}/devel/p5-JIRA-Client \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		subversion>=1.4.0:${PORTSDIR}/devel/subversion
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
