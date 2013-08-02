# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-HomeDir
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get home directory for self or other users

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS=	p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which

USES=		perl5
USE_PERL5=	configure

MAN3=		File::HomeDir.3 \
		File::HomeDir::Darwin.3 \
		File::HomeDir::Darwin::Carbon.3 \
		File::HomeDir::Darwin::Cocoa.3 \
		File::HomeDir::Driver.3 \
		File::HomeDir::FreeDesktop.3 \
		File::HomeDir::MacOS9.3 \
		File::HomeDir::Test.3 \
		File::HomeDir::Unix.3 \
		File::HomeDir::Windows.3

.include <bsd.port.mk>
