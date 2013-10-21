# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	jwasm
PORTVERSION=	211
CATEGORIES=	devel
MASTER_SITES=	http://www.japheth.de/Download/JWasm/
DISTNAME=	JWasm${PORTVERSION}s

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Fork of OpenWatcom x86 assembler with AMD64 support

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	amd64 i386

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USES=	gmake
MAKEFILE=	GccUnix.mak

PORTDOCS=	*
PLIST_FILES=	bin/jwasm

post-patch:
	@${REINPLACE_CMD} -e \
		'/^extra_c_flags/s|-O2|$$(CFLAGS)| ; \
		 /^CC/s| =| ?=| ; \
		 s|-s -o|-o|' ${WRKSRC}/GccUnix.mak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GccUnixR/jwasm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>
