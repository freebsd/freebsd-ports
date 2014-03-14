# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ftjam
PORTVERSION=	2.5.2
CATEGORIES=	devel
MASTER_SITES=	SF/freetype/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small build tool that can be used as a replacement for make(1)

OPTIONS_DEFINE=	DOCS

USES=		gmake tar:bzip2

PORTDOCS=	Jam.html \
		Jambase.html \
		Jamfile.html \
		Porting \
		README \
		RELNOTES \
		jam.c

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	@${REINPLACE_CMD} -e '/^CC/s|=|?=|; /^CFLAGS/s|=|?=|' \
	    ${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/bin.unix/jam ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
