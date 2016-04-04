# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-Blowfish
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLU
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	POE::Component::IRC plugin tthat provides blowfish encryption

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=0.37:devel/p5-POE \
		p5-POE-Component-IRC>=5.07:irc/p5-POE-Component-IRC \
		p5-Crypt-Blowfish_PP>=1.12:security/p5-Crypt-Blowfish_PP
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"

USES=		perl5 shebangfix
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	synopsis.pl
SHEBANG_FILES=	examples/synopsis.pl

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
