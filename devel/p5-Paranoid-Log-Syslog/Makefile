# $FreeBSD$

PORTNAME=	Paranoid-Log-Syslog
PORTVERSION=	2.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Syslog support for Paranoid::Log

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Paranoid>=2:devel/p5-Paranoid \
		p5-Unix-Syslog>0:sysutils/p5-Unix-Syslog
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	YES
USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%PERL5_MAN3%%/Paranoid::Log::Syslog.3.gz \
		%%SITE_PERL%%/Paranoid/Log/Syslog.pm

.include <bsd.port.mk>
