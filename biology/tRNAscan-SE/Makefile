# Created by: chuynh@biolateral.com.au
# $FreeBSD$

PORTNAME=	tRNAscan-SE
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://selab.janelia.org/pub/software/tRNAscan-SE/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved tool for transfer RNA detection

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

USES=		perl5 tar:Z
MAKE_ARGS=	BINDIR="${PREFIX}/bin" \
		LIBDIR="${DATADIR}" \
		CC="${CC}" \
		CFLAGS="${CFLAGS}"

PLIST_FILES+=	bin/covels-SE bin/coves-SE bin/eufindtRNA bin/tRNAscan-SE bin/trnascan-1.4 \
		man/man1/tRNAscan-SE.1.gz
PORTDATA=	*
PORTDOCS=	Manual.ps

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|tRNAscanSE setpaths|tRNAscanSE|g ; \
		 s|if tRNAscan-SE|if ./tRNAscan-SE|g' ${WRKSRC}/Makefile

do-install:
.for f in covels-SE coves-SE eufindtRNA trnascan-1.4
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/tRNAscan-SE ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tRNAscan-SE.man ${STAGEDIR}${MANPREFIX}/man/man1/tRNAscan-SE.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in TPCsignal Dsignal *.cm gcode.*
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Manual.ps ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
