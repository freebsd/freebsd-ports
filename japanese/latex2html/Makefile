# New ports collection makefile for:	 ja-latex2html
# Date created:		3 Apr 1999
# Whom:			Sugimoto Sadahiro <ixtl@utmc.or.jp>
#
# $FreeBSD$
#
# Default image format is GIF.
# If you prefer PNG to GIF, define USE_PNG (`make -DUSE_PNG`).

PORTNAME=	latex2html
PORTVERSION=	${VERSION}j${JP_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www-dsed.llnl.gov/files/programs/unix/latex2html/sources/ \
		ftp://ftp.mpn.com/pub/nikos/latex2html-mirror/sources/ \
		http://www.topstudio.co.jp/~kmuto/software/latex2html/patch/98-1/
DISTNAME=	${PORTNAME}-${VERSION}p1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${VERSION}jpatch-${JP_VERSION}.tar.gz

MAINTAINER=	ixtl@utmc.or.jp

RUN_DEPENDS=	${PREFIX}/bin/latex:${PORTSDIR}/print/latex \
		${PREFIX}/bin/dvips:${PORTSDIR}/print/dvips \
		${PREFIX}/bin/gs:${PORTSDIR}/print/ghostscript5 \
		${LOCALBASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm

.ifdef USE_PNG
RUN_DEPENDS +=	${X11BASE}/bin/pnmtopng:${PORTSDIR}/graphics/pnmtopng
.endif

VERSION=	98.1
JP_VERSION=	2.1

WRKSRC=	${WRKDIR}/latex2html
USE_PERL5=	yes
NO_BUILD=	yes
PATCHDIR=	${WRKDIR}/patches

L2HDIR=	${PREFIX}/share/jlatex2html

pre-patch:
	@${MKDIR} ${PATCHDIR}
	@for p in ${MASTERDIR}/patches/patch-*; do \
		${SED} -e "s:@Id@:Id:" $$p > ${PATCHDIR}/$${p##*/}; \
	done

post-patch:
	@${PATCH} ${PATCH_ARGS} -o ${WRKDIR}/jlatex2html < ${WRKDIR}/jlatex2html.dif
	@${PATCH} ${PATCH_ARGS} -o ${WRKDIR}/jlatex2html.config \
		< ${WRKDIR}/jlatex2html.config.dif
	@for file in latex2html/configure-pstoimg latex2html/texexpand \
		latex2html/pstoimg latex2html/pstoimg_nopipes \
		 jlatex2html.config jlatex2html; do \
		${PERL} -pi.org -e \
			"s|LATEX2HTMLDIR\s*=.*;|LATEX2HTMLDIR='${L2HDIR}';|; s|^use lib.*;|use lib '${L2HDIR}';|;" \
			${WRKDIR}/$$file; \
	done
.ifdef USE_PNG
	@${PERL} -pi -e "s|IMAGE_TYPE=.*;|IMAGE_TYPE='png';|" \
		${WRKDIR}/jlatex2html.config
.endif

do-install:
	@${MKDIR} ${L2HDIR}
	@${INSTALL_DATA} ${FILESDIR}/local.pm ${L2HDIR}
	@ for dir in makeseg IndicTeX-HTML cweb2html docs example icons.gif icons.png styles tests versions; do \
		${CP} -R ${WRKSRC}/$$dir ${L2HDIR}; \
	done
	@ for prog in Override.pm configure-pstoimg install-test makemap pstoimg\
		pstoimg_nopipes texexpand; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$prog ${L2HDIR}; \
	done
	@ for file in FAQ MANIFEST README README.dvips dot.latex2html-init; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${L2HDIR}; \
	done
	@${MKDIR} ${PREFIX}/share/texmf/tex/latex/jlatex2html
	@${INSTALL_DATA} ${WRKSRC}/texinputs/* ${PREFIX}/share/texmf/tex/latex/jlatex2html
	@${INSTALL_SCRIPT} ${WRKDIR}/jlatex2html ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/jlatex2html ${L2HDIR}
	@${INSTALL_DATA} ${WRKDIR}/jlatex2html.config ${L2HDIR}
	@ for dir in styles versions; do \
		${MKDIR} ${L2HDIR}/$$dir; \
		${INSTALL_DATA} ${WRKDIR}/$$dir/* ${L2HDIR}/$$dir; \
	done

.include <bsd.port.mk>
