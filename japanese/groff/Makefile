# New ports collection makefile for:	ja-groff
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	groff
PORTVERSION=	1.17.2
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_LOCAL:S,%SUBDIR%,okazaki/&,} \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${TMAC_DISTNAME}.tar.gz

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	okazaki/groff
PATCHFILES=	${DISTNAME}-jgroff-0.0.2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@FreeBSD.org

TMAC_DATE=	20020120
TMAC_DISTNAME=	tmac-${TMAC_DATE}

USE_GMAKE=	yes
USE_AUTOCONF=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-nippon
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"

TMACBASE=	${WRKDIR}/${TMAC_DISTNAME}
TMACDIR=	share/groff/${PORTVERSION}/tmac
SITETMACDIR=	share/groff/site-tmac
MDOCDIR=	${TMACDIR}/mdoc
INFODIR=	${PREFIX}/info
DOCSDIR=	${PREFIX}/share/doc/jgroff
PLIST_SUB=	GROFF_VERSION=${PORTVERSION}

MAN1SRC=	eqn.1 indxbib.1 lookbib.1 neqn.1 nroff.1 pic.1 \
		refer.1 soelim.1 tbl.1 troff.1 grn.1

MAN1=		${MAN1SRC:S/^/g/g} \
		addftinfo.1 afmtodit.1 grodvi.1 \
		groff.1 grog.1 \
		grohtml.1 grolbp.1 grolj4.1 grops.1 grotty.1 \
		hpftodit.1 lkbib.1 pfbtops.1 tfmtodit.1
MAN5=		groff_font.5 groff_out.5 groff_tmac.5
MAN7=		groff.7 groff_char.7 groff_man.7 groff_mdoc.7 \
		groff_me.7 groff_mm.7 groff_mmse.7 groff_ms.7 \
		groff_mwww.7 mmroff.7 roff.7

SITETMACFILES=	mdoc.local
TMACFILES=	tmac.orig_me tmac.vgrind \
		an-old.tmac doc.tmac e.tmac
MDOCFILES=	eucJP doc-common doc-syms

DOCUMENTS=	ChangeLog.jp NEWS PROBLEMS README README.jp \
		doc/meintro.me doc/meref.me doc/pic.ms

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 350001
WITHOUT_INFO=	yes
PLIST_SUB+=	INFO="@comment "
.else
PLIST_SUB+=	INFO=""
.endif

TEXINFO_FILTER=	-e 's/\@acronym/\@var/g;' \
		-e 's/ifnottex/ifinfo/g;' \
		-e 's/ifnotinfo/iftex/g;' \
		-e 's/\@option/\@samp/g;' \
		-e 's/\@env/\@code/g;'

# workaround for autoconf-2.13

CONFIGUREIN_FILTER=	\
		-e 's|AC_INIT|dnl|g;' \
		-e 's|AC_CONFIG_SRCDIR|AC_INIT|g;' \
		-e 's|AC_OUTPUT|dnl|g;' \
		-e 's|AC_CONFIG_FILES|AC_OUTPUT|g;'

ACLOCAL_FILTER=	-e 's/AC_LANG_POP\(C\+\+\)/AC_LANG_RESTORE/g;' \
		-e 's/AC_LANG_PUSH\(C\+\+\)/AC_LANG_SAVE\nAC_LANG_CPLUSPLUS/g;'

post-extract:
	${LN} -sf configure.ac ${WRKSRC}/configure.in

post-patch:
	${PERL} -pi ${CONFIGUREIN_FILTER} ${WRKSRC}/configure.in
	${PERL} -pi ${ACLOCAL_FILTER} ${WRKSRC}/aclocal.m4

post-build:
.if !defined(WITHOUT_INFO)
	cd ${WRKSRC}/doc && makeinfo --no-split groff.texinfo
.endif

post-install:
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

.include <bsd.port.post.mk>
