# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	POE-Session-Irssi
PORTVERSION=	0.50
PORTREVISION=	3
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARTIJN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Emit POE events for Irssi signals

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-POE>=1.003:devel/p5-POE \
		p5-Sub-Uplevel>0:devel/p5-Sub-Uplevel \
		p5-POE-Loop-Glib>=0.036:devel/p5-POE-Loop-Glib
RUN_DEPENDS=	p5-POE>=1.003:devel/p5-POE \
		p5-Sub-Uplevel>0:devel/p5-Sub-Uplevel \
		p5-POE-Loop-Glib>=0.036:devel/p5-POE-Loop-Glib \
		irssi:irc/irssi

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
CONFIGURE_ARGS+=	INSTALLDIRS=site
USES=		perl5 shebangfix
SHEBANG_FILES=	samples/clean-backlog.pl
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
