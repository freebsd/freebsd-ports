# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Config-IniHash
PORTVERSION=	3.01.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Config/JENDA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for reading and writing INI files

RUN_DEPENDS=	p5-Hash-Case>=0:${PORTSDIR}/devel/p5-Hash-Case \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Hash-WithDefaults>=0.04:${PORTSDIR}/devel/p5-Hash-WithDefaults
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

.include <bsd.port.mk>
