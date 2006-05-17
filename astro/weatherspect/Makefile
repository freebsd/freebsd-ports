# New ports collection makefile for:	weatherspect
# Date created:		2006-05-16
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	weatherspect
PORTVERSION=	1.6
CATEGORIES=	astro
MASTER_SITES=	http://www.robobunny.com/projects/weatherspect/ \
		http://olofsson.de/mirror/distfiles/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	simon@olofsson.de
COMMENT=	Weather simulation in ASCII art

RUN_DEPENDS=	\
${SITE_PERL}/Term/Animation.pm:${PORTSDIR}/devel/p5-Term-Animation \
${SITE_PERL}/Weather/Underground.pm:${PORTSDIR}/astro/p5-Weather-Underground

NO_BUILD=	yes
PLIST_FILES=	bin/weatherspect

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
