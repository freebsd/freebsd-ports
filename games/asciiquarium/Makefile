PORTNAME=	asciiquarium
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.robobunny.com/projects/asciiquarium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aquarium/sea animation in ASCII art

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt

RUN_DEPENDS=	p5-Term-Animation>=0:devel/p5-Term-Animation

USES=		perl5 shebangfix
SHEBANG_FILES=	asciiquarium

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/asciiquarium
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-test:
	(sleep 0.1 && echo p && sleep 0.1 && echo p && sleep 0.1 && echo r && \
		sleep 0.1 && echo q) | ${STAGEDIR}${PREFIX}/bin/asciiquarium

.include <bsd.port.mk>
