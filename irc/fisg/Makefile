# Created by: Pasi Hirvonen <psh@iki.fi>
# $FreeBSD$

PORTNAME=	fisg
PORTVERSION=	0.3.12
CATEGORIES=	irc
MASTER_SITES=	http://www.tnsp.org/files/

MAINTAINER=	psh@iki.fi
COMMENT=	Fast IRC statistics generator

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PORTDOCS=	README FAQ
PORTEXAMPLES=	example.cfg users.cfg

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX|PREFIX?|' \
		-e 's|^CC|CC?|' -e 's|^CFLAGS|CFLAGS?|' ${WRKSRC}/src/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data/ && ${INSTALL_DATA} *.css *.gif *.png \
		${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/fisg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/src/fisg.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
