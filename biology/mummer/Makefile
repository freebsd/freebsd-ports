# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	mummer
PORTVERSION=	3.23
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	SF
DISTNAME=	MUMmer${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular system for rapid whole genome alignment

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5 shebangfix

SHEBANG_FILES=	scripts/*.csh scripts/*.pl
SHEBANG_LANG=	csh
perl_OLD_CMD=	__PERL_PATH
csh_OLD_CMD=	__CSH_PATH
csh_CMD=	/bin/csh
_SHEBANG_REINPLACE_ARGS+=	-e "s|__BIN_DIR|${PREFIX}/bin|g;s|__AUX_BIN_DIR|${PREFIX}/libexec/mummer|g;s|__SCRIPT_DIR|${PREFIX}/libexec/mummer|g"

PROGRAMS=	annotate combineMUMs delta-filter gaps \
		mgaps mummer repeat-match show-aligns \
		show-coords show-diff show-snps show-tiling
SCRIPTS=	dnadiff.pl exact-tandems.csh mapview.pl mummerplot.pl nucmer.pl \
		nucmer2xfig.pl promer.pl run-mummer1.csh run-mummer3.csh
LIBEXEC=	Foundation.pm tandem-repeat.awk
DOCUMENTS=	COPYRIGHT INSTALL LICENSE README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${file} ${STAGEDIR}${PREFIX}/bin/${file:R}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/aux_bin/* ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${LIBEXEC:S|^|${WRKSRC}/scripts/|} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCUMENTS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
