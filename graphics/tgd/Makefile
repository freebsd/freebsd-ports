# New ports collection makefile for:	tgd
# Version required:			1.2c
# Date created:				22 February 1999
# Whom:	      				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

DISTNAME=	tgd1.2c
PKGNAME=	tgd-1.2c
CATEGORIES=	graphics
MASTER_SITES=	ftp://probe.nalusda.gov/pub/treegenes/ \
		ftp://dendrome.ucdavis.edu/pub/tgd/

MAINTAINER=	mharo@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

BROKEN=	gd changes
FORBIDDEN=	author hadn\'t had time to update for gd changes

ALL_TARGET=	tgd
DOCS=		README arc.gif cap.gif char.gif fill.gif fontdemo \
		fontdemo.gif gd.html gifcap.pl helloworld.gif \
		helloworld.pl keygifcap.gif keypad.gif keypad.html \
		keypad.inp keypad.map keypad.pl poly.gif polydemo \
		rainbow.gif rainbow.pl tgd.gif tgd.html
pre-build:
	${CP} ${FILESDIR}/tgdcommand.h ${WRKSRC}/
	${CP} ${FILESDIR}/tgdgd.h ${WRKSRC}/
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tgd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} -m 755 ${PREFIX}/share/doc/tgd
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/tgd
.endfor
.endif

.include <bsd.port.mk>
