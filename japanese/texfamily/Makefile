# New ports collection makefile for:	texfamily
# Date created:		9 Feb 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	texfamily
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/texfam-1.2/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs/texfamily
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTFILES=	teTeX-src-1.0.7${EXTRACT_SUFX} \
		texfam-1.2${EXTRACT_SUFX} \
		texfam-texmf-j1.9${EXTRACT_SUFX} \
		texfam-texmf-latex209${EXTRACT_SUFX} \
		web2c-j1.9${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	teTeX-src-1.0.7${EXTRACT_SUFX} \
		texfam-1.2${EXTRACT_SUFX} \
		texfam-texmf-j1.9${EXTRACT_SUFX} \
		texfam-texmf-latex209${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A Japanese TeX, NTT JTeX (TeXfamily)

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USE_GMAKE=	yes
TEXMFTMP=	${WRKDIR}/texmf-tmp

.if make(pre-build) || make(do-build)
MAKE_ENV=	TEXMFLOCALDIR=${LOCALBASE}/${TEXMFLOCALDIR} \
		TEXMFDUMP=${TEXMFTMP} \
		TEXMFDISTDIR=${LOCALBASE}/${TEXMFDISTDIR}
.endif
ALL_TARGET=	default
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		TEXMFLOCALDIR=${TEXMFLOCALDIR}

INSTALL_WRKSRC=	${WRKDIR}/teTeX-1.0/texk/web2c-j
WRKSRC=		${WRKDIR}/teTeX-1.0

KANJICODE?=	euc
TEXMFDIR?=	share/texmf
TEXMFDISTDIR?=	share/texmf-dist
TEXMFLOCALDIR?=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXMFCNF_SRC=	${WRKDIR}/teTeX-1.0/texk/kpathsea/texmf.cnf
TEXMFCNF_DST=	${PREFIX}/${TEXMFDIR}/web2c/jtex/texmf.cnf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

INSTDIRS=	doc fonts jbibtex jtex source tex
DOC_FILES=	COPYRIGHT COPYRIGHT.jis Changes.txt README.txt

CONFIGURE_ARGS=	--enable-local-texmf=${TEXMFLOCALDIR} \
		--disable-multiplatform \
		--without-texinfo --without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--without-xdvik --without-oxdvik \
		--without-dvipsk --without-odvipsk \
		--without-x11 --without-dvipdfm --without-omega \
		--without-pdftex --without-pdfetex \
		--with-etex=no
post-extract:
	cd ${WRKSRC}/texk && \
		${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/web2c-j1.9${EXTRACT_SUFX}

pre-build:
	${MKDIR} ${TEXMFTMP}
	cd ${WRKDIR} && \
		${TAR} cf - ${INSTDIRS} | \
			(cd ${TEXMFTMP} && ${TAR} xf -)
	${MKDIR} ${TEXMFTMP}/jtex/generic/config
	${CP} ${FILESDIR}/language.dat ${TEXMFTMP}/jtex/generic/config/
	${SETENV} ${MAKE_ENV} ${MKTEXLSR} ${TEXMFTMP}

post-install:
	cd ${WRKDIR} && \
		${TAR} cf - ${INSTDIRS} | \
			(cd ${PREFIX}/${TEXMFLOCALDIR} && ${TAR} xf -)
	${INSTALL_DATA} ${TEXMFCNF_SRC} ${TEXMFCNF_DST}
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
