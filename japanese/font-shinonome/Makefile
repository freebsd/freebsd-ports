# New ports collection makefile for: shinonome
# Date created:		June 15 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	shinonome
PORTVERSION=	0.9.11
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://openlab.ring.gr.jp/efont/dist/shinonome/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese 12,14,16 dot fonts

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local
DOCSDIR=	share/doc/shinonome
CONFIGURE_ARGS=	--with-fontdir=${PREFIX}/${FONTSDIR} --enable-compress

.include <bsd.port.pre.mk>

FONTNAMES=\
	shnm6x12a    shnm6x12ab   shnm6x12ai   shnm6x12abi   \
	shnm6x12r    shnm6x12rb   shnm6x12ri   shnm6x12rbi   \
	shnm7x14a    shnm7x14ab   shnm7x14ai   shnm7x14abi   \
	shnm7x14r    shnm7x14rb   shnm7x14ri   shnm7x14rbi   \
	shnm8x16a    shnm8x16ab   shnm8x16ai   shnm8x16abi   \
	shnm8x16r    shnm8x16rb   shnm8x16ri   shnm8x16rbi   \
	shnm9x18a    shnm9x18ab   shnm9x18ai   shnm9x18abi   \
	shnm9x18r    shnm9x18rb   shnm9x18ri   shnm9x18rbi   \
	shnmk12      shnmk12b     shnmk12i     shnmk12bi     \
	shnmk12p     shnmk12pb    shnmk12pi    shnmk12pbi    \
	shnmk12min   shnmk12minb  shnmk12mini  shnmk12minbi  \
	shnmk12maru  shnmk12marub shnmk12marui shnmk12marubi \
	shnmk14      shnmk14b     shnmk14i     shnmk14bi     \
	shnmk14min   shnmk14minb  shnmk14mini  shnmk14minbi  \
	shnmk16      shnmk16b     shnmk16i     shnmk16bi     \
	shnmk16min   shnmk16minb  shnmk16mini  shnmk16minbi
DOCS=	AUTHORS BUGS ChangeLog ChangeLog.0 DESIGN.12 DESIGN.14 \
	DESIGN.16 DESIGN.18 INSTALL README THANKS TODO LICENSE

PLIST_SUB+=	FONTSDIR=${FONTSDIR} DOCSDIR=${DOCSDIR}

post-build:
	@${ECHO_CMD} -n 'Compressing PCF fonts'
.for i in ${FONTNAMES}
	@${ECHO_CMD} -n '.'
	@cd ${WRKSRC}; ${GZIP_CMD} ${i}.pcf
.endfor
	@${ECHO_CMD} 'Done'

pre-su-install:
	@${MKDIR} ${PREFIX}/${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fonts.alias ${PREFIX}/${DOCSDIR}
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
# Do not use original install target since it forces to delete fonts.alias
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
