# New ports collection makefile for:	p5-IniConf
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IniConf
PORTVERSION=	0.92
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IniConf
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}.pm-${PORTVERSION}

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		IniConf.pm.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
