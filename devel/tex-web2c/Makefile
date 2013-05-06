# $FreeBSD$

PORTNAME=	web2c
PORTVERSION=	20120701
CATEGORIES=	devel
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${PORTVERSION}-source

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX implementation translating WEB to C

LIB_DEPENDS=	openjpeg:${PORTSDIR}/graphics/openjpeg \
		png15:${PORTSDIR}/graphics/png \
		zzip:${PORTSDIR}/devel/zziplib

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	kpathsea
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES}
EXTRACT_FILES=	${DISTNAME}/build-aux \
		${DISTNAME}/libs/obsdcompat \
		${DISTNAME}/libs/xpdf \
		${DISTNAME}/texk/web2c
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OBSDCOMPAT_INCLUDES=-I${WRKSRC}/../../libs/obsdcompat
CONFIGURE_ARGS= --disable-luatex \
		--disable-xetex \
		--disable-aleph \
		--disable-ptex \
		--disable-eptex \
		--disable-uptex \
		--disable-euptex \
		--with-x=no \
		--without-mf-x-toolkit \
		--with-system-icu \
		--with-icu-includes=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-libpng-includes=${LOCALBASE}/include \
		--with-libpng-libdir=${LOCALBASE}/lib \
		--with-system-zlib \
		--with-system-zziplib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_SAFE=	yes

INFO=	web2c
NO_MANCOMPRESS=	yes
MAN1=	ctie.1 cweb.1 tangle.1 tie.1 bibtex.1 dvicopy.1 dvitomp.1	\
	dvitype.1 gftodvi.1 gftopk.1 gftype.1 mft.1 patgen.1 pktogf.1	\
	pktype.1 pltotf.1 pooltype.1 tftopl.1 vftovp.1 vptovf.1		\
	weave.1 tex.1 mf.1 mpost.1 pdftex.1 pdftosrc.1 ttf2afm.1	\
	amstex.1	\
	eplain.1 latex.1 pdfetex.1
MLINKS=	cweb.1 ctangle.1 \
	cweb.1 cweave.1 \
	mf.1 mf-nowin.1 \
	pdftex.1 pdflatex.1

pre-configure:
	for D in libs/obsdcompat libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

.include <bsd.port.mk>
