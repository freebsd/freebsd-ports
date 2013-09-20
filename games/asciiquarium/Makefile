# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asciiquarium
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.robobunny.com/projects/asciiquarium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aquarium/sea animation in ASCII art

RUN_DEPENDS=	p5-Term-Animation>=0:${PORTSDIR}/devel/p5-Term-Animation

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
USES=		perl5
PLIST_FILES=	bin/asciiquarium

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
