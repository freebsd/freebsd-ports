# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Log-Report
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Report a problem, pluggable handlers and language support

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-GlobalDestruction>=0.09:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Log-Report-Optional>=1.01:${PORTSDIR}/devel/p5-Log-Report-Optional \
		p5-String-Print>=0.13:${PORTSDIR}/textproc/p5-String-Print
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
