# New ports collection makefile for:	M+ Fonts_J
# Date created:		July 17 2002
# Whom:			The 244th namelessness at 2ch.net
#
# $FreeBSD$
#

PORTNAME=	mplusfonts
PORTVERSION=	1.0.4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://downloads.sourceforge.jp/mplus-fonts/2050/ \
		http://wids.net/archive/mplusfonts/distfiles/
DISTNAME=	mplus_fonts_J-${PORTVERSION}

MAINTAINER=	Ys@PixyGarden.net

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTNAME=	mplus_j12b mplus_j12b_iso8859 mplus_j12b_jisx0201 \
		mplus_j12r mplus_j12r_iso8859 mplus_j12r_jisx0201
DOCS=		LICENSE README_J

FONTSDIR=	${PREFIX}/lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR:S/${PREFIX}\///}

do-build:
.for file in ${FONTNAME}
	cd ${WRKSRC} && \
		bdftopcf ${file}.bdf | ${GZIP_CMD} > ${file}.pcf.gz
.endfor

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${FONTSDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@(cd ${FONTSDIR} ; mkfontdir)

.include <bsd.port.post.mk>
