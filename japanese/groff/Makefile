# New ports collection makefile for:	ja-groff
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	groff
PORTVERSION=	1.18.1
DISTVERSIONSUFFIX=	.1
PORTREVISION=	10
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_LOCAL:S,%SUBDIR%,okazaki/&,} \
		${MASTER_SITE_DEBIAN:S,$,:debian,}
MASTER_SITE_SUBDIR=	groff/:DEFAULT pool/main/g/groff/:debian
DISTFILES=	${DISTNAME:S,-,_,}.orig${EXTRACT_SUFX}:debian ${TMAC_DISTNAME}.tar.gz

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/g/groff
PATCHFILES=	${DISTNAME:S,-,_,}-12.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese enhancement of GNU groff

.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS=	pnmcut:${PORTSDIR}/graphics/netpbm
.endif

TMAC_DATE=	20030521
TMAC_DISTNAME=	tmac-${TMAC_DATE}_2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

CONFIGURE_ARGS=	--enable-multibyte
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}" \
		LIBS="-L${LOCALBASE}/lib -liconv"
CFLAGS+=	-I${LOCALBASE}/include

TMACBASE=	${WRKDIR}/${TMAC_DISTNAME}
TMACDIR=	share/groff/${PORTVERSION}/tmac
SITETMACDIR=	share/groff/site-tmac
MDOCDIR=	${TMACDIR}/mdoc
PLIST_SUB=	GROFF_VERSION=${PORTVERSION}

SUB_FILES=	mdoc.local
SUB_LIST=	OSREL=${OSREL}

TMACFILES=	tmac.orig_me tmac.vgrind \
		an-old.tmac doc.tmac e.tmac
MDOCFILES=	ja.eucJP doc-common doc-syms

DOCUMENTS=	ChangeLog.jp NEWS PROBLEMS README README.jp

MAN1=		addftinfo.1 afmtodit.1 \
		eqn.1 eqn2graph.1 \
		grn.1 grodvi.1 groff.1 groffer.1 grog.1 \
		grohtml.1 grolbp.1 grolj4.1 grops.1 grotty.1 \
		hpftodit.1 indxbib.1 lkbib.1 lookbib.1 mmroff.1 \
		neqn.1 nroff.1 pfbtops.1 pic.1 pic2graph.1 \
		refer.1 soelim.1 tbl.1 tfmtodit.1 troff.1
MAN5=		groff_font.5 groff_out.5 groff_tmac.5
MAN7=		ditroff.7 groff.7 groff_char.7 groff_diff.7 \
		groff_man.7 groff_mdoc.7 \
		groff_me.7 groff_mm.7 groff_mmse.7 groff_mom.7 groff_ms.7 \
		groff_trace.7 groff_www.7 roff.7

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install_doc
PORTDOCS=	${PORTVERSION}
.endif

# nl_langinfo(CODESET) drops the support of ja_JP.EUC after 5.1-RELEASE
.if ${OSVERSION} > 501100
LOCALE_CMD?=	/usr/bin/locale
.if exists(${LOCALE_CMD})
CHARMAP!=	${LOCALE_CMD} charmap
.if (${CHARMAP} == "EUC")
MAKE_ENV=	LC_ALL=C
pre-build:
	@${ECHO_CMD} "Warning: Your current locale setting is not supported by the system."
.endif
.endif
.endif

# formatting groff.info requires texinfo 4.2
.if ${OSVERSION} < 470000
WITHOUT_INFO=	yes
.endif

.if defined(WITHOUT_INFO)
PLIST_SUB+=	INFO="@comment "
.else
INFO=		groff
PLIST_SUB+=	INFO=""
.endif

# wchar.h is exist since 4.4-RELEASE
.if ${OSVERSION} < 440000
WITHOUT_WCHAR_H=	yes
.endif

POST_INSTALL_SEQ=	install-links
.if !defined(NOPORTDOCS)
POST_INSTALL_SEQ+=	install-documents
.endif

post-patch:
	${REINPLACE_CMD} -e 's|\(install_data\)|\1 install_doc|g;' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -E -e 's|^@setfilename +groff|&.info|g;' \
		${WRKSRC}/doc/groff.texinfo
.if defined(WITHOUT_WCHAR_H)
	${REINPLACE_CMD} -e 's|#include <wchar[.]h>||g;' \
		${WRKSRC}/src/libs/libgroff/encoding.cc
.endif

post-build:
	${RM} -f ${WRKSRC}/doc/groff ${WRKSRC}/doc/groff-*
.if !defined(WITHOUT_INFO)
	cd ${WRKSRC}/doc && makeinfo --no-split groff.texinfo
.endif
	cd ${WRKSRC} && ${FIND} font -name DESC \
	| ${XARGS} ${REINPLACE_CMD} -E -e 's|pro +(gxditview)|pro ${X11BASE}/bin/\1|g;'
	cd ${WRKSRC} && ${FIND} font -name DESC \
	| ${XARGS} ${REINPLACE_CMD} -E -e 's|pro +([^/].*)|pro ${PREFIX}/bin/\1|g;'

post-install: ${POST_INSTALL_SEQ}
.for F in ${TMACFILES}
	${INSTALL_DATA} ${TMACBASE}/${F} ${PREFIX}/${TMACDIR}
.endfor
.for F in ${MDOCFILES}
	${INSTALL_DATA} ${TMACBASE}/mdoc/${F} ${PREFIX}/${MDOCDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/mdoc.local ${PREFIX}/${SITETMACDIR}

install-documents:
	@${MKDIR} ${DOCSDIR}/${PORTVERSION}
.for F in ${DOCUMENTS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${F} ${DOCSDIR}/${PORTVERSION}
.endfor
.if !defined(WITHOUT_INFO)
	${INSTALL_DATA} ${WRKSRC}/doc/groff.info ${PREFIX}/${INFO_PATH}
.endif

install-links:
.for F in eqn neqn pic tbl
	${LN} -sf ${F} ${PREFIX}/bin/g${F}
.endfor

.include <bsd.port.post.mk>
