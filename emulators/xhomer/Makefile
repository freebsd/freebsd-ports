# Created by: trasz
# $FreeBSD$

PORTNAME=	xhomer
DISTVERSION=	9-16-06
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://xhomer.isani.org/xhomer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for the DEC Pro 350 computer

USES=		gmake tar:tgz
USE_XORG=	xt sm ice xext x11
ALL_TARGET=	clean xhomer
INSTALL_TARGET=	# empty
CFLAGS+=	-Wall -ffloat-store

SUB_FILES=	pkg-message

PLIST_FILES=	bin/xhomer
PORTDOCS=	README LICENSE SIMH
PORTEXAMPLES=	xhomer.cfg

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xhomer ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xhomer.cfg ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
