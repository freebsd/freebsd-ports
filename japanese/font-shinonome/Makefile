# New ports collection makefile for: shinonome
# Date created:		June 15 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	shinonome
PORTVERSION=	0.9.6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://openlab.ring.gr.jp/efont/dist/shinonome/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local
DOCSDIR=	share/doc/shinonome
CONFIGURE_ARGS=	--with-fontdir=${PREFIX}/${FONTSDIR} --enable-compress

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTNAMES=\
	shnm6x12a    shnm7x14rbi  shnmk12maru    shnmk14bi    \
	shnm6x12ab   shnm7x14ri   shnmk12marub   shnmk14i     \
	shnm6x12abi  shnm8x16a    shnmk12marubi  shnmk14min   \
	shnm6x12ai   shnm8x16ab   shnmk12marui   shnmk14minb  \
	shnm6x12r    shnm8x16abi  shnmk12min     shnmk14minbi \
	shnm6x12rb   shnm8x16ai   shnmk12minb    shnmk14mini  \
	shnm6x12rbi  shnm8x16r    shnmk12minbi   shnmk16      \
	shnm6x12ri   shnm8x16rb   shnmk12mini    shnmk16b     \
	shnm7x14a    shnm8x16rbi  shnmk12p       shnmk16bi    \
	shnm7x14ab   shnm8x16ri   shnmk12pb      shnmk16i     \
	shnm7x14abi  shnmk12      shnmk12pbi     shnmk16min   \
	shnm7x14ai   shnmk12b     shnmk12pi      shnmk16minb  \
	shnm7x14r    shnmk12bi    shnmk14        shnmk16minbi \
	shnm7x14rb   shnmk12i     shnmk14b       shnmk16mini
DOCS=	AUTHORS BUGS ChangeLog ChangeLog.0 DESIGN.12 DESIGN.14 \
	DESIGN.16 DESIGN.18 INSTALL README THANKS TODO

PLIST_SUB+=	FONTSDIR=${FONTSDIR} DOCSDIR=${DOCSDIR}

post-build:
.for i in ${FONTNAMES}
	@cd ${WRKSRC}; ${GZIP_CMD} ${i}.pcf
.endfor

pre-install:
	@${MKDIR} ${PREFIX}/${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fonts.alias ${PREFIX}/${DOCSDIR}
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
.for i in ${FONTNAMES}
	${INSTALL_DATA} ${WRKSRC}/${i}.pcf.gz ${PREFIX}/${FONTSDIR}
.endfor
	@mkfontdir ${PREFIX}/${FONTSDIR}
	@${CAT} ${PREFIX}/${DOCSDIR}/fonts.alias >> ${PREFIX}/${FONTSDIR}/fonts.alias
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
