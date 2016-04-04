# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pushmi
PORTVERSION=	1.0.0
PORTREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
DISTNAME=	Pushmi-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subversion repository replication tool

LICENSE=	APACHE20

RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion \
		p5-App-CLI>=0.06:devel/p5-App-CLI \
		p5-Cache-Memcached>=0:databases/p5-Cache-Memcached \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck \
		svk>=2.0.0:devel/svk
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-IPC-Run3>=0:devel/p5-IPC-Run3 \
		p5-RunApp>=0.13:devel/p5-RunApp \
		p5-Test-Output>=0:devel/p5-Test-Output \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2

USES=		perl5
USE_PERL5=	configure
USE_APACHE=	22+

.include <bsd.port.mk>
