# New ports collection makefile for:	p5-Audio-CD
# Date created:				22 Oct 2000
# Whom:	      				Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	Audio-CD
PORTVERSION=	0.04
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Audio
PKGNAMEPREFIX=	p5-

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

USE_PERL5=	YES

MAN3=		Audio::CD.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
