# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	blat
PORTVERSION=	34
CATEGORIES=	biology
MASTER_SITES=	http://www.soe.ucsc.edu/~kent/src/
DISTNAME=	${PORTNAME}Src${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast tool for local sequence similarity searches

USES=		gmake
EXTRACT_SUFX=	.zip
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}Src
MAKE_ENV+=	HOME="${WRKSRC}/${BINDIR}" MACHTYPE="${ARCH}"

SUB_FILES=	pkg-message

EXECUTABLES=	blat faToNib faToTwoBit gfClient gfServer nibFrag \
		pslPretty pslReps pslSort twoBitInfo twoBitToFa

PLIST_FILES+=	${EXECUTABLES:S,^,bin/,}
PORTDOCS=	README
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${MKDIR} ${WRKSRC}/bin/${ARCH}
	@${MKDIR} ${WRKSRC}/lib/${ARCH}
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS)=,\1 ?=,g;s,-Werror,,g' \
		${WRKSRC}/inc/common.mk

do-install:
.for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${ARCH}/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/webBlat
	${INSTALL_PROGRAM} ${WRKSRC}/webBlat/webBlat ${STAGEDIR}${DATADIR}/webBlat
	${INSTALL_DATA} ${WRKSRC}/webBlat/install.txt ${STAGEDIR}${DATADIR}/webBlat
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
