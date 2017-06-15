# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	groff
PORTVERSION=	1.18.1
DISTVERSIONSUFFIX=	.1
PORTREVISION=	17
CATEGORIES=	japanese print
MASTER_SITES=	LOCAL/hrs
DISTFILES=	${DISTNAME:S,-,_,}.orig${EXTRACT_SUFX} ${TMAC_DISTNAME}.tar.gz

PATCH_SITES=	LOCAL/hrs
PATCHFILES=	${DISTNAME:S,-,_,}-21.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese enhancement of GNU groff

LICENSE=	GPLv2

USES=		iconv:wchar_t cpe gmake makeinfo shebangfix
SHEBANG_FILES=	src/utils/afmtodit/afmtodit.pl \
		contrib/mm/mmroff.pl
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-multibyte
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install install_doc
PLIST_SUB=	GROFF_VERSION=${PORTVERSION}
SUB_FILES=	mdoc.local
SUB_LIST=	OSREL=${OSREL}
PORTDOCS=	*
PORTEXAMPLES=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}/${PORTVERSION}
INFO=		groff

CONFLICTS=	groff-[0-9]* mdocml-[0-9]*

TMAC_DISTNAME=	tmac-20030521_2
TMACFILES=	tmac.orig_me tmac.vgrind \
		an-old.tmac doc.tmac e.tmac
MDOCFILES=	ja.eucJP doc-common doc-syms

post-patch:
	${REINPLACE_CMD} -E -e 's|^@setfilename +groff|&.info|g;' \
	    ${WRKSRC}/doc/groff.texinfo

post-build:
	${RM} ${WRKSRC}/doc/groff ${WRKSRC}/doc/groff-*
	cd ${WRKSRC}/doc && makeinfo --no-split groff.texinfo
	cd ${WRKSRC} && ${FIND} font -name DESC \
	    | ${XARGS} ${REINPLACE_CMD} -E \
	    -e 's|pro +(gxditview)|pro ${LOCALBASE}/bin/\1|g;' \
	    -e 's|pro +([^/].*)|pro ${PREFIX}/bin/\1|g;'

post-install:
	cd ${WRKDIR}/${TMAC_DISTNAME} && ${INSTALL_DATA} \
	    ${TMACFILES} ${STAGEDIR}${DATADIR}/${PORTVERSION}/tmac
	cd ${WRKDIR}/${TMAC_DISTNAME}/mdoc && ${INSTALL_DATA} \
	    ${MDOCFILES} ${STAGEDIR}${DATADIR}/${PORTVERSION}/tmac/mdoc
	${INSTALL_DATA} ${WRKDIR}/mdoc.local ${STAGEDIR}${DATADIR}/site-tmac
	${INSTALL_DATA} ${WRKSRC}/doc/groff.info \
	    ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC} && ${INSTALL_DATA} \
	    ChangeLog.jp NEWS PROBLEMS README README.jp ${STAGEDIR}${DOCSDIR}
	for F in eqn neqn pic tbl; do \
		${LN} -sf $$F ${STAGEDIR}${PREFIX}/bin/g$$F; \
	done

.include <bsd.port.mk>
