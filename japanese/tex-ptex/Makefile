PORTNAME=	ptex
PORTVERSION=	3.6
PORTREVISION=	4
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
WWW=		https://ctan.org/pkg/ptex

USES=				localbase perl5 pkgconfig tar:xz tex
USE_TEX=			fmtutil formats kpathsea ptexenc web2c
TEXHASHDIRS=			${TEXMFDISTDIR} ${TEXMFVARDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=			build-aux libs/xpdf texk/web2c
EXTRACT_AFTER_ARGS_TEXMF=	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
				--strip-components 1 --no-same-permission \
				--no-same-owner \
				${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
EXTRACT_FILES_TEXMF=		texmf-dist/doc/ptex texmf-dist/doc/platex \
				texmf-dist/doc/uptex texmf-dist/doc/uplatex \
				texmf-dist/doc/fonts/japanese-otf \
				texmf-dist/fonts/vf/public/japanese-otf \
				texmf-dist/fonts/tfm/public/japanese-otf \
				texmf-dist/fonts/ofm/public/japanese-otf \
				texmf-dist/source/fonts/japanese-otf \
				texmf-dist/source/platex \
				texmf-dist/source/uplatex texmf-dist/tex/ptex \
				texmf-dist/tex/uptex texmf-dist/tex/platex \
				texmf-dist/tex/uplatex \
				texmf-dist/tex/generic/hyph-utf8/patterns/ptex \
				texmf-dist/fonts/map/dvipdfmx/updmap/kanjix.map
WRKSRC=				${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=			yes
EXCLUDE_ENGINES=		aleph etex pdftex luatex luajittex mf mf-nowin \
				otangle mp pmp upmp web2c web-progs xetex tex \
				synctex mflua mfluajit luahbtex luajithbtex

CONFIGURE_ARGS=		${EXCLUDE_ENGINES:S/^/--disable-/} \
			--enable-eptex \
			--enable-euptex \
			--enable-ptex \
			--enable-uptex \
			--with-system-zlib \
			--without-x
.for L in kpathsea ptexenc
CONFIGURE_ARGS+=	--with-$L-include=${LOCALBASE}/include \
			--with-$L-libdir=${LOCALBASE}/lib \
			--with-system-$L
.endfor
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=		ptex uptex

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
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/mkjvf \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkcidvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkjp04tfmvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkmlcidvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mktfm.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mktfm_sp.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkutf32list.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkutfvf.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/mkutfvf_sp.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/umkvpkana.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/script/umkpkana.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/japanese-otf/umkjvf
	${FIND} -s ${STAGEDIR}${PREFIX}/share -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
