# $FreeBSD$

PORTNAME=	ptex
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXLIVE}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	ASCII Japanese pTeX

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	kpathsea web2c ptexenc texmf formats fmtutil
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	\
	build-aux \
	libs/obsdcompat \
	libs/xpdf \
	texk/web2c
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE=	20120701
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/ptex \
	texmf-dist/doc/platex \
	texmf-dist/doc/uptex \
	texmf-dist/doc/uplatex \
	texmf-dist/doc/fonts/japanese-otf \
	texmf-dist/doc/fonts/japanese-otf-uptex \
	texmf-dist/doc/fonts/jfontmaps \
	texmf-dist/fonts/source/ptex \
	texmf-dist/fonts/ovp/public/japanese-otf-uptex \
	texmf-dist/fonts/vf/ptex \
	texmf-dist/fonts/vf/uptex \
	texmf-dist/fonts/vf/public/japanese-otf \
	texmf-dist/fonts/vf/public/japanese-otf-uptex \
	texmf-dist/fonts/type1/ptex \
	texmf-dist/fonts/tfm/ptex \
	texmf-dist/fonts/tfm/uptex \
	texmf-dist/fonts/tfm/public/japanese-otf-uptex \
	texmf-dist/fonts/tfm/public/japanese-otf \
	texmf-dist/fonts/ofm/public/japanese-otf \
	texmf-dist/source/fonts/uptex \
	texmf-dist/source/fonts/japanese-otf-uptex \
	texmf-dist/source/fonts/japanese-otf \
	texmf-dist/source/platex \
	texmf-dist/source/uplatex \
	texmf-dist/tex/ptex \
	texmf-dist/tex/uptex \
	texmf-dist/tex/platex \
	texmf-dist/tex/uplatex \
	texmf-dist/tex/generic/hyph-utf8/patterns/ptex \
	texmf-dist/fonts/map/dvipdfmx/ptex \
	texmf-dist/fonts/map/dvipdfmx/uptex \
	texmf-dist/fonts/map/dvipdfmx/japanese-otf-uptex \
	texmf-dist/fonts/map/dvipdfmx/japanese-otf \
	texmf-dist/fonts/map/dvipdfmx/jfontmaps \
	texmf/fonts/map/dvipdfmx/updmap/kanjix.map \
	texmf-dist/fonts/cmap/uptex
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OBSDCOMPAT_INCLUDES=-I${WRKSRC}/../../libs/obsdcompat
EXCLUDE_ENGINES= aleph etex luatex pdftex mf mf-nowin xetex
#		--disable-web-progs \
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--enable-ptex \
		--enable-eptex \
		--enable-uptex \
		--enable-euptex \
		--disable-mp \
		--enable-web2c \
		--enable-web-progs \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-ptexenc \
		--with-ptexenc-includes=${LOCALBASE}/include \
		--with-ptexenc-libdir=${LOCALBASE}/lib \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
TEX_FORMATS=	ptex uptex

pre-configure:
	for D in libs/obsdcompat libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>
