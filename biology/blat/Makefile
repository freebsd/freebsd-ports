# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	blat
PORTVERSION=	34
CATEGORIES=	biology
MASTER_SITES=	http://www.soe.ucsc.edu/~kent/src/
DISTNAME=	${PORTNAME}Src${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast tool for local sequence similarity searches

USE_ZIP=	yes
USE_GMAKE=	yes
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

NO_STAGE=	yes
post-patch:
	@${MKDIR} ${WRKSRC}/bin/${ARCH}
	@${MKDIR} ${WRKSRC}/lib/${ARCH}
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS)=,\1 ?=,g;s,-Werror,,g' \
		${WRKSRC}/inc/common.mk

.include <bsd.port.options.mk>

do-install:
.for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${ARCH}/${exe} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}/webBlat
	${INSTALL_PROGRAM} ${WRKSRC}/webBlat/webBlat ${DATADIR}/webBlat
	${INSTALL_DATA} ${WRKSRC}/webBlat/install.txt ${DATADIR}/webBlat
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
