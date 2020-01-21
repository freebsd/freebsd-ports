# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	jwasm
PORTVERSION=	2.13
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Fork of OpenWatcom x86 assembler with AMD64 support

LICENSE=	OpenWatcom
LICENSE_NAME=	Sybase Open Watcom Public License version 1.0
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		alias dos2unix gmake

USE_GITHUB=     yes
GH_ACCOUNT=	JWasm
GH_PROJECT=	${GH_ACCOUNT}

OPTIONS_DEFINE=	DOCS

MAKEFILE=	GccUnix.mak

PORTDOCS=	*
PLIST_FILES=	bin/jwasm

MAKE_JOBS_UNSAFE=	yes

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
