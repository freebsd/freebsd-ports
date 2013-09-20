# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	weatherspect
PORTVERSION=	1.9
CATEGORIES=	astro
MASTER_SITES=	http://www.robobunny.com/projects/weatherspect/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	simon@olofsson.de
COMMENT=	Weather simulation in ASCII art

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Term-Animation>=0:${PORTSDIR}/devel/p5-Term-Animation \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

PORTSCOUT=	skipv:1.31	# Wrong versioning upstream

NO_STAGE=	yes
NO_BUILD=	yes
USES=		perl5
PLIST_FILES=	bin/weatherspect

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
