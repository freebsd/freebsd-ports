# New ports collection makefile for:	asciiquarium
# Date created:				16 Sep 2005
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asciiquarium
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.robobunny.com/projects/asciiquarium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aquarium/sea animation in ASCII art

RUN_DEPENDS=	${SITE_PERL}/Term/Animation.pm:${PORTSDIR}/devel/p5-Term-Animation

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/asciiquarium

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
