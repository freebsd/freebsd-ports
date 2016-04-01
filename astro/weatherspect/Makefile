# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	weatherspect
PORTVERSION=	1.11
CATEGORIES=	astro
MASTER_SITES=	http://www.robobunny.com/projects/weatherspect/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Weather simulation in ASCII art

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Term-Animation>=0:devel/p5-Term-Animation \
		p5-libwww>=0:www/p5-libwww

PORTSCOUT=	skipv:1.31

NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	bin/weatherspect

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
