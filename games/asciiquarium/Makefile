# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asciiquarium
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.robobunny.com/projects/asciiquarium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aquarium/sea animation in ASCII art

RUN_DEPENDS=	p5-Term-Animation>=0:devel/p5-Term-Animation

USES=		perl5
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/asciiquarium

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
