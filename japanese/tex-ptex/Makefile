PORTNAME=	ptex
PORTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	ja-tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${TEXLIVE_VERSION}-source${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	ASCII Japanese pTeX

USES=		localbase tar:xz perl5 pkgconfig
USE_TEX=	kpathsea web2c ptexenc texmf formats fmtutil
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		texk/web2c
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
	    --strip-components 1 --no-same-permission --no-same-owner \
	    ${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTNAME_TEXMF=	texlive-${TEXLIVE_VERSION}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/ptex \
	texmf-dist/doc/platex \
	texmf-dist/doc/uptex \
	texmf-dist/doc/uplatex \
	texmf-dist/doc/fonts/japanese-otf \
	texmf-dist/doc/fonts/japanese-otf-uptex \
	texmf-dist/fonts/vf/public/japanese-otf \
	texmf-dist/fonts/vf/public/japanese-otf-uptex \
	texmf-dist/fonts/tfm/public/japanese-otf-uptex \
	texmf-dist/fonts/tfm/public/japanese-otf \
	texmf-dist/fonts/ofm/public/japanese-otf \
	texmf-dist/source/fonts/japanese-otf-uptex \
	texmf-dist/source/fonts/japanese-otf \
	texmf-dist/source/platex \
	texmf-dist/source/uplatex \
	texmf-dist/tex/ptex \
	texmf-dist/tex/uptex \
	texmf-dist/tex/platex \
	texmf-dist/tex/uplatex \
	texmf-dist/tex/generic/hyph-utf8/patterns/ptex \
	texmf-dist/fonts/map/dvipdfmx/japanese-otf \
	texmf-dist/fonts/map/dvipdfmx/updmap/kanjix.map
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=aleph etex pdftex luatex luajittex mf mf-nowin \
		otangle mp pmp upmp web2c web-progs xetex tex synctex \
		mflua mfluajit luahbtex luajithbtex

CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-ptex \
		--enable-eptex \
		--enable-uptex \
		--enable-euptex \
		--with-system-zlib \
		--without-x
.for L in kpathsea ptexenc
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	ptex uptex

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-configure:
	for D in libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}; \
	done

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${TEXLIVE_VERSION}-texmf${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_TEXMF}

post-install:
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf-uptex/umkjvf \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf-uptex/script/mkutf32list.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf-uptex/script/umkvpkana.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf-uptex/script/mkutfvf_sp.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf-uptex/script/umkpkana.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf-uptex/script/mktfm_sp.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/mkjvf \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkmlcidvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkutfvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkjp04tfmvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkcidvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mktfm.pl
	${FIND} -s ${STAGEDIR}${PREFIX}/share -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
