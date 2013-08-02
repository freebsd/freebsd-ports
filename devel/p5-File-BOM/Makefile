# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	File-BOM
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to handle Unicode byte order marks

RUN_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \
		p5-Module-Build>=0.3607:${PORTSDIR}/devel/p5-Module-Build
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	File::BOM.3

.include <bsd.port.mk>
