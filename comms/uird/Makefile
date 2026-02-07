PORTNAME=	uird
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	http://kbinstuff.googlepages.com/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Universal IR Receiver Daemon
WWW=		http://kbinstuff.googlepages.com/uirduniversalirreceiverdaemon

USES=		perl5 gmake tar:tgz

ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/uird
PORTDOCS=	Documentation

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}\ $${CFLAGS}|; /strip/d' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uird ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
