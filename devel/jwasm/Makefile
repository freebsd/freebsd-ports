# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	jwasm
PORTVERSION=	210
CATEGORIES=	devel
MASTER_SITES=	http://www.japheth.de/Download/JWasm/
DISTNAME=	JWasm${PORTVERSION}s

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of OpenWatcom's x86 assembler with AMD64 support

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	amd64 i386

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKEFILE=	GccUnix.mak

PORTDOCS=	*
PLIST_FILES=	bin/jwasm

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^extra_c_flags/s|-O2|$$(CFLAGS)| ; \
		 /^CC/s| =| ?=| ; \
		 s|-s -o|-o|' ${WRKSRC}/GccUnix.mak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GccUnixR/jwasm ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	@${GZIP_CMD} ${DOCSDIR}/*.txt
	@${MKDIR} ${DOCSDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${DOCSDIR}/manual
	@${GZIP_CMD} ${DOCSDIR}/manual/*.txt
.endif

.include <bsd.port.mk>
