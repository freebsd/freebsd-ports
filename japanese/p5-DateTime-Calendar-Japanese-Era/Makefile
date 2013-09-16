# New ports collection makefile for:	p5-DateTime-Calendar-Japanese-Era
# Date created:		2007-05-16
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Japanese-Era
PORTVERSION=	0.08001
PORTREVISION=	1
CATEGORIES=	japanese devel perl5
MASTER_SITES=	CPAN

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Extension for Japanese Eras

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Module-Install>=0.91:${PORTSDIR}/devel/p5-Module-Install \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-YAML-Tiny>=1.38:${PORTSDIR}/textproc/p5-YAML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

MAN3=		DateTime::Calendar::Japanese::Era.3

post-patch:
	@${RM} -rf ${WRKSRC}/inc

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
