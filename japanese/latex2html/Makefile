# New ports collection makefile for:	 ja-latex2html
# Date created:		3 Apr 1999
# Whom:			Sugimoto Sadahiro <ixtl@utmc.or.jp>
#
# $FreeBSD$
#
# Default image format is PNG.
# If you prefer GIF to PNG, define WITH_GIF (`make -DWITH_GIF`).

PORTNAME=	latex2html
PORTVERSION=	${VERSION}j${JP_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.topstudio.co.jp/~kmuto/debian/private/dists/stable/contrib/source/
DISTNAME=	jlatex2html_${VERSION}+${JP_VERSION}.orig

PATCH_SITES=	http://www.topstudio.co.jp/~kmuto/software/latex2html/patch/99-1/
PATCHFILES=	jlatex2html-${VERSION}+${JP_VERSION}.dif.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ixtl@utmc.or.jp

RUN_DEPENDS=	platex:${PORTSDIR}/japanese/ptex-euc \
		dvips:${PORTSDIR}/japanese/dvipsk-vflib \
		gs:${PORTSDIR}/japanese/vfghostscript55 \
		anytopnm:${PORTSDIR}/graphics/netpbm \
		nkf:${PORTSDIR}/japanese/nkf

VERSION=	99.1
JP_VERSION=	3.01

WRKSRC=		${WRKDIR}/latex2html
USE_PERL5=	yes
NO_BUILD=	yes

L2HDIR=		${PREFIX}/share/latex2html

post-patch:
.for f in configure-pstoimg install-test latex2html makemap \
	ps2img-n pstoimg pstoimg_nopipes texexpand
		${PERL} -e "s:^\#!/usr/local/bin/perl:\#!${PERL}:" \
		-pi ${WRKSRC}/$f
.endfor

do-install:
	${MKDIR} ${L2HDIR}
.for dir in IndicTeX-HTML XyMTeX-HTML cweb2html docs/changebar \
	docs/hthtml docs/psfiles docs example foilhtml icon-dos icons.gif \
	icons.png makeseg styles tests texinputs versions
		${CP} -R ${WRKSRC}/${dir} ${L2HDIR}
.endfor
.for prog in Override.pm configure-pstoimg install-test latex2html \
	makemap ps2img-n pstoimg pstoimg_nopipes texexpand
		${INSTALL_SCRIPT} ${WRKSRC}/${prog} ${L2HDIR}
.endfor
.for file in .dvipsrc Changes FAQ MANIFEST README README.dvips \
	README.patch TODO dot.latex2html-init latex2html.config readme.hthtml
		${INSTALL_DATA} ${WRKSRC}/${file} ${L2HDIR}
.endfor
	${MKDIR} ${PREFIX}/share/texmf/tex/latex/latex2html
	${INSTALL_DATA} ${WRKSRC}/texinputs/* ${PREFIX}/share/texmf/tex/latex/latex2html
.ifdef WITH_GIF
	cd ${L2HDIR}; ${CAT} ${FILESDIR}/answer-gif | ${PERL} install-test
.else
	cd ${L2HDIR}; ${CAT} ${FILESDIR}/answer-png | ${PERL} install-test
.endif
	${INSTALL_SCRIPT} ${L2HDIR}/latex2html ${PREFIX}/bin

.include <bsd.port.mk>
