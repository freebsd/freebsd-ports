# New ports collection makefile for:	ja-groff
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	groff
PORTVERSION=	0.100
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTNAME=	${PORTNAME}-1.15

PATCH_SITES=	http://w3.mtci.ne.jp/~refactor/GNU/
PATCHFILES=	${DISTNAME}-jgroff-${PORTVERSION}-pl1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@be.to

USE_GMAKE=	yes
USE_AUTOCONF=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-nippon
CONFIGURE_ENV=	INSTALL="${INSTALL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"
PLIST_SUB=	PORTDOCDIR="${PORTDOCDIR}"

TMACBASE=	/usr/share/tmac
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
		groff_me.7 groff_mm.7 groff_mmse.7 groff_ms.7 groff_msafer.7 \

TMACFILES=	tmac.an tmac.andoc tmac.groff_an tmac.orig_me tmac.vgrind \
		eqnrc troffrc
MDOCFILES=	doc-common doc-syms
LOCALEFILES=	locale-list eucJP

DOCUMENTS=	ChangeLog.jp NEWS PROBLEMS README README.jp \
		doc/meintro.me doc/meref.me doc/pic.ms

.if exists(${TMACBASE}/locale/hyphen.us-ru)
WITH_TMAC_LOCALE=	yes
.else
# There is no valid locale subdirectory.
WITHOUT_TMAC_LOCALE=	yes
PERL_ARGS= -e 's,^\@dirrm *share/groff/tmac/locale\n$$,,;'
.if exists(${TMACBASE}/hyphen.us-ru)
# hyphen.us-ru is in TMACBASE.
PERL_ARGS+= -e 's,locale/(hyphen.us-ru)$$,$$1,;'
.else
# There is no hyphen.us-ru.
PERL_ARGS+= -e 's,^.*hyphen.us-ru\n$$,,;'
.endif
.endif

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
	${CP} -p ${TMACFILES:S|^|${TMACBASE}/|g} ${PREFIX}/${TMACDIR}
	${CP} -p ${MDOCFILES:S|^|${TMACBASE}/mdoc/|g} ${PREFIX}/${MDOCDIR}
	${MKDIR} ${PREFIX}/${LOCALEDIR}
	${INSTALL_DATA} ${LOCALEFILES:S|^|${FILESDIR}/|g} ${PREFIX}/${LOCALEDIR}
.if defined(WITH_TMAC_LOCALE) && !defined(WITHOUT_TMAC_LOCALE)
	${CP} -pr ${TMACBASE}/locale ${PREFIX}/${TMACDIR}
.elif exists(${TMACBASE}/hyphen.us-ru)
	${CP} -p ${TMACBASE}/hyphen.us-ru ${PREFIX}/${TMACDIR}
.endif
.if defined(PERL_ARGS) && !empty(PERL_ARGS)
	${PERL} -pi ${PERL_ARGS} ${TMPPLIST}
.endif
	${PATCH} -d ${PREFIX}/${TMACDIR} < ${FILESDIR}/rc.diff

install-documents:
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCUMENTS} ${PREFIX}/${PORTDOCDIR}

install-info:
	${INSTALL_DATA} ${WRKSRC}/doc/groff ${INFODIR}
	install-info ${INFODIR}/groff ${INFODIR}/dir

.include <bsd.port.post.mk>
