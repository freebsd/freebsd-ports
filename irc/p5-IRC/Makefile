# New ports collection makefile for:	p5-IRC
# Date created:				07 August 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	p5-IRC
PORTVERSION=	0.63
CATEGORIES=	irc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
DISTNAME=	Net-IRC-${PORTVERSION}

MAINTAINER=	jedgar@fxp.org

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		\
		Net::Connection.3 \
		Net::DCC.3 \
		Net::Event.3 \
		Net::IRC.3

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
