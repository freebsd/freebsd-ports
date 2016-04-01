# $FreeBSD$

PORTNAME=	App-SD
PORTVERSION=	0.75
PORTREVISION=	2
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SPANG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Peer-to-peer replicated distributed issue tracker

LICENSE=	MIT

BUILD_DEPENDS=	p5-DateTime>=:devel/p5-DateTime \
		p5-DateTime-Format-Natural>=0:devel/p5-DateTime-Format-Natural \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Prophet>=0:databases/p5-Prophet \
		p5-Test-Script-Run>=0.02:devel/p5-Test-Script-Run
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GITHUB GOOGLECODE HIVEMINDER TRAC RT
OPTIONS_DEFAULT=	GITHUB GOOGLECODE HIVEMINDER TRAC RT
GITHUB_DESC=		Enable github sync
GOOGLECODE_DESC=	Add support for google code
HIVEMINDER_DESC=	Enable huveminder sync
TRAC_DESC=		Enable trac sync
RT_DESC=		Enable rt sync

GITHUB_BUILD_DEPENDS=	p5-Net-GitHub>=0.18:net/p5-Net-GitHub
GITHUB_RUN_DEPENDS=	p5-Net-GitHub>=0.18:net/p5-Net-GitHub

GOOGLECODE_BUILD_DEPENDS=	p5-Net-Google-Code>=0.14:net/p5-Net-Google-Code
GOOGLECODE_RUN_DEPENDS=		p5-Net-Google-Code>=0.14:net/p5-Net-Google-Code

HIVEMINDER_BUILD_DEPENDS=	p5-Net-Jifty>=0.09:net/p5-Net-Jifty \
				p5-Email-Address>=0:mail/p5-Email-Address \
				p5-Email-MIME>=0:mail/p5-Email-MIME
HIVEMINDER_RUN_DEPENDS=		${HIVEMINDER_BUILD_DEPENDS}

TRAC_BUILD_DEPENDS=	p5-Net-Trac>=0.13:www/p5-Net-Trac
TRAC_RUN_DEPENDS=	p5-Net-Trac>=0.13:www/p5-Net-Trac

RT_BUILD_DEPENDS=	p5-RT-Client-REST>=0:www/p5-RT-Client-REST
RT_RUN_DEPENDS=		p5-RT-Client-REST>=0:www/p5-RT-Client-REST

.include <bsd.port.mk>
