# New ports collection makefile for:	ja-groff
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	groff
PORTVERSION=	1.18.1
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_LOCAL:S,%SUBDIR%,okazaki/&,} \
		${MASTER_SITE_GNU:S,$,:gnu,}
MASTER_SITE_SUBDIR=	groff/:DEFAULT,gnu
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gnu ${TMAC_DISTNAME}.tar.gz

PATCH_SITES=	http://people.debian.org/~ukai/groff/
PATCHFILES=	${DISTNAME:S,-,_,}-7.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@FreeBSD.org
COMMENT=	Japanese enhancement of GNU groff

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	pnmcut:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	pnmcut:${PORTSDIR}/graphics/netpbm

TMAC_DATE=	20030521
TMAC_DISTNAME=	tmac-${TMAC_DATE}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--enable-multibyte
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}" \
		LIBS="-L${LOCALBASE}/lib -liconv"
CFLAGS+=	-I${LOCALBASE}/include

TMACBASE=	${WRKDIR}/${TMAC_DISTNAME}
TMACDIR=	share/groff/${PORTVERSION}/tmac
SITETMACDIR=	share/groff/site-tmac
MDOCDIR=	${TMACDIR}/mdoc
INFODIR=	${PREFIX}/info
DOCSDIR=	${PREFIX}/share/doc/groff/${PORTVERSION}
PLIST_SUB=	GROFF_VERSION=${PORTVERSION}

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

SITETMACFILES=	mdoc.local
TMACFILES=	tmac.orig_me tmac.vgrind \
		an-old.tmac doc.tmac e.tmac
MDOCFILES=	ja.eucJP doc-common doc-syms

DOCUMENTS=	ChangeLog.jp NEWS PROBLEMS README README.jp

.include <bsd.port.pre.mk>

# formatting groff.info requires texinfo 4.2
.if ${OSVERSION} < 470000
WITHOUT_INFO=	yes
PLIST_SUB+=	INFO="@comment "
.else
PLIST_SUB+=	INFO=""
.endif

# wchar.h is exist since 4.4-RELEASE
.if ${OSVERSION} < 440000
WITHOUT_WCHAR_H=	yes
.endif

post-patch:
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
	| ${XARGS} ${REINPLACE_CMD} -e 's|pro \(.*\)|pro ${PREFIX}/bin/\1|g;'

post-install: install-links
.if !defined(WITHOUT_INFO)
	@${MAKE} install-info
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} install-documents
.endif
.for FILE in ${SITETMACFILES}
	${INSTALL_DATA} ${TMACBASE}/${FILE} ${PREFIX}/${SITETMACDIR}
.endfor
.for FILE in ${TMACFILES}
	${INSTALL_DATA} ${TMACBASE}/${FILE} ${PREFIX}/${TMACDIR}
.endfor
.for FILE in ${MDOCFILES}
	${INSTALL_DATA} ${TMACBASE}/mdoc/${FILE} ${PREFIX}/${MDOCDIR}
.endfor

install-documents:
	@${MKDIR} ${DOCSDIR}
	cd ${INSTALL_WRKSRC} \
		&& ${INSTALL_DATA} ${DOCUMENTS} ${DOCSDIR}

install-info:
	${INSTALL_DATA} ${WRKSRC}/doc/groff ${INFODIR}
	install-info ${INFODIR}/groff ${INFODIR}/dir

install-links:
.for FILE in eqn neqn pic tbl
	${LN} -sf ${FILE} ${PREFIX}/bin/g${FILE}
.endfor

.include <bsd.port.post.mk>
