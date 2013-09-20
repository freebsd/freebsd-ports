# Created by: chuynh@biolateral.com.au
# $FreeBSD$

PORTNAME=	tRNAscan-SE
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://selab.janelia.org/pub/software/tRNAscan-SE/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved tool for transfer RNA detection

USES=		perl5
MAKE_ARGS=	BINDIR="${PREFIX}/bin" \
		LIBDIR="${DATADIR}" \
		CC="${CC}" \
		CFLAGS="${CFLAGS}"

PLIST_FILES+=	bin/covels-SE bin/coves-SE bin/eufindtRNA bin/tRNAscan-SE bin/trnascan-1.4
MAN1=		tRNAscan-SE.1
PORTDATA=	*
PORTDOCS=	Manual.ps

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|tRNAscanSE setpaths|tRNAscanSE|g ; \
		 s|if tRNAscan-SE|if ./tRNAscan-SE|g' ${WRKSRC}/Makefile

do-install:
.for f in covels-SE coves-SE eufindtRNA trnascan-1.4
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/tRNAscan-SE ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tRNAscan-SE.man ${MANPREFIX}/man/man1/tRNAscan-SE.1
	@${MKDIR} ${DATADIR}
.for f in TPCsignal Dsignal *.cm gcode.*
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.include <bsd.port.options.mk>

#
# have to install before testing as path to data files is hardcoded
#
post-install:
	@ cd ${WRKSRC} && ${MAKE} testrun
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Manual.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
