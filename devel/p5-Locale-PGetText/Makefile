# New ports collection makefile for:   p5-Locale-PGetText
# Date created:        27 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Locale-PGetText
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	nakai@FreeBSD.org

USE_PERL5=	YES

# There is also perl man but how to manage /usr/local/man 
# and /usr/local/lib/perl5/%%PERL_VER%%/man

MAN1=		MsgFormat.1 XText.1
#MAN3=		Locale::PGettext.3
#MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
