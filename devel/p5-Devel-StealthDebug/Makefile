# Created by: Alex Kapranoff <alex@kapranoff.ru>
# $FreeBSD$

PORTNAME=	Devel-StealthDebug
PORTVERSION=	1.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple non-intrusive debug module

BUILD_DEPENDS=	p5-Filter-Simple>=0:${PORTSDIR}/textproc/p5-Filter-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

.include <bsd.port.mk>
