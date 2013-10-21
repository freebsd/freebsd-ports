# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	POE-Session-Irssi
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARTIJN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Emit POE events for Irssi signals

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-POE>=1.003:${PORTSDIR}/devel/p5-POE \
		p5-Sub-Uplevel>0:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-POE-Loop-Glib>=0.036:${PORTSDIR}/devel/p5-POE-Loop-Glib
RUN_DEPENDS=	p5-POE>=1.003:${PORTSDIR}/devel/p5-POE \
		p5-Sub-Uplevel>0:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-POE-Loop-Glib>=0.036:${PORTSDIR}/devel/p5-POE-Loop-Glib \
		irssi:${PORTSDIR}/irc/irssi

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
CONFIGURE_ARGS+=	INSTALLDIRS=site
USES=		perl5
USE_PERL5=	configure

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
