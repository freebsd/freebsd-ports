# New ports collection makefile for:	p5-POE-Session-Irssi
# Date created:	   Jul 29 2010
# Whom:		   Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Session-Irssi
PORTVERSION=	0.50
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@beardz.net
COMMENT=	Emit POE events for Irssi signals

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Sub/Uplevel.pm:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-POE-Loop-Glib>=0.036:${PORTSDIR}/devel/p5-POE-Loop-Glib
RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Sub/Uplevel.pm:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-POE-Loop-Glib>=0.036:${PORTSDIR}/devel/p5-POE-Loop-Glib \
		irssi:${PORTSDIR}/irc/irssi

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Session::Irssi.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
