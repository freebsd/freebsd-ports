# New ports collection makefile for:	ja-groff
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	groff
PORTVERSION=	0.100
PORTREVISION=	3
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	groff okazaki/groff
DISTNAME=	${PORTNAME}-1.15
DISTFILES=	${DISTNAME}.tar.gz ${TMAC_DISTNAME}.tar.gz

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR= okazaki
PATCHFILES=	${DISTNAME}-jgroff-${PORTVERSION}-pl1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@FreeBSD.org

TMAC_DATE=	20010314
TMAC_DISTNAME=	tmac-${TMAC_DATE}

USE_GMAKE=	yes
USE_AUTOCONF=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-nippon
CONFIGURE_ENV=	INSTALL="${INSTALL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"

TMACBASE=	${WRKDIR}/${TMAC_DISTNAME}
TMACDIR=	share/groff/tmac
MDOCDIR=	${TMACDIR}/mdoc
LOCALEDIR=	${MDOCDIR}/locale
INFODIR=	${PREFIX}/info
PORTDOCDIR=	share/doc/jgroff

DESCFILES=	devascii/DESC.proto devdvi-ascii/DESC.in \
		devdvi/DESC.in devhtml/DESC devlatin1/DESC.proto \
		devlj4/DESC.in devnippon/DESC.proto devps/DESC.in

MAN1SRC=	eqn.1 indxbib.1 lookbib.1 nroff.1 pic.1 \
		refer.1 soelim.1 tbl.1 troff.1

MAN1=		${MAN1SRC:S/^/g/g} addftinfo.1 afmtodit.1 grodvi.1 \
		groff.1 grog.1 grohtml.1 grolj4.1 grops.1 grotty.1 \
		hpftodit.1 lkbib.1 pfbtops.1 psbb.1 tfmtodit.1
MAN5=		groff_font.5 groff_out.5
MAN7=		groff_char.7 groff_man.7 groff_mdoc.7 groff_mdoc.samples.7 \
		groff_me.7 groff_mm.7 groff_mmse.7 groff_ms.7 groff_msafer.7

TMACFILES=	tmac.X tmac.a4 \
		tmac.an tmac.an-old tmac.andoc tmac.arkup \
		tmac.doc tmac.dvi tmac.html \
		tmac.latin1 tmac.lbp tmac.m \
		tmac.man tmac.mandoc tmac.markup tmac.mdoc \
		tmac.me tmac.ms tmac.mse \
		tmac.orig_me tmac.pspic tmac.s tmac.safer \
		tmac.trace tmac.tty tmac.tty-char tmac.vgrind \
		eqnrc troffrc troffrc-end
MDOCFILES=	doc-common doc-ditroff doc-nroff doc-syms
LOCALEFILES=	locale-list eucJP

DOCUMENTS=	ChangeLog.jp NEWS PROBLEMS README README.jp \
		doc/meintro.me doc/meref.me doc/pic.ms

TROFFRC_FILTER=	-e 's,^(.do ds troffrc!koi8-r tmac.tty)$$,$$1\n.do ds troffrc!nippon tmac.tty,;'
EQNRC_FILTER=	-e 's,^(ifdef koi8-r ! define n %1% !)$$,$$1\nifdef nippon ! define n %1% !,;'

#for not writing "/usr/local" explicitly in the patch
post-patch:
	cd ${WRKSRC} \
	&& ${PERL} -pi -e 's:^(postpro +):$$1${PREFIX}/bin/:g;' ${DESCFILES}

.include <bsd.port.pre.mk>

post-build:
	cd ${WRKSRC}/doc && makeinfo --no-split groff.texinfo

post-install:
	@${MAKE} install-info
.if !defined(NOPORTDOCS)
	@${MAKE} install-documents
.endif
.for FILE in ${TMACFILES}
	${INSTALL_DATA} ${TMACBASE}/${FILE} ${PREFIX}/${TMACDIR}
.endfor
.for FILE in ${MDOCFILES}
	${INSTALL_DATA} ${TMACBASE}/mdoc/${FILE} ${PREFIX}/${MDOCDIR}
.endfor
	${MKDIR} ${PREFIX}/${LOCALEDIR}
.for FILE in ${LOCALEFILES}
	${INSTALL_DATA} ${FILESDIR}/${FILE} ${PREFIX}/${LOCALEDIR}
.endfor
	${MKDIR} ${PREFIX}/${TMACDIR}/locale
	${INSTALL_DATA} ${TMACBASE}/locale/hyphen.* ${PREFIX}/${TMACDIR}/locale
.if defined(TROFFRC_FILTER) && !empty(TROFFRC_FILTER)
	${PERL} -pi ${TROFFRC_FILTER} ${PREFIX}/${TMACDIR}/troffrc
.endif
.if defined(EQNRC_FILTER) && !empty(EQNRC_FILTER)
	${PERL} -pi ${EQNRC_FILTER} ${PREFIX}/${TMACDIR}/eqnrc
.endif

install-documents:
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCUMENTS} ${PREFIX}/${PORTDOCDIR}

install-info:
	${INSTALL_DATA} ${WRKSRC}/doc/groff ${INFODIR}
	install-info ${INFODIR}/groff ${INFODIR}/dir

.include <bsd.port.post.mk>
