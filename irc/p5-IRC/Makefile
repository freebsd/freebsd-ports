# New ports collection makefile for:	p5-IRC
# Date created:				07 August 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IRC
PORTVERSION=	0.75
CATEGORIES=	irc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net/JMUHLICH
PKGNAMEPREFIX=	p5-

MAINTAINER=	jedgar@fxp.org
COMMENT=	Perl5 modules to implement the IRC protocol (RFC 1459)

PERL_CONFIGURE=	yes

MAN3=		Net::Connection.3 \
		Net::DCC.3 \
		Net::Event.3 \
		Net::IRC.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/INET.pm:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/INET.pm:${PORTSDIR}/devel/p5-IO
post-patch:
	@${PERL} -pi -e '$$_ = "" if /(use|no) warnings/' ${WRKSRC}/EventQueue.pm
	@${PERL} -pi -e 's/^our (\S+);/use vars qw($$1);/' ${WRKSRC}/Event.pm
.endif

.include <bsd.port.post.mk>
