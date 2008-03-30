# New ports collection makefile for: shinonome
# Date created:		June 15 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	shinonome
PORTVERSION=	0.9.11p1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://openlab.jp/efont/dist/shinonome/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese 12,14,16 dot fonts

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/p.*$//}

USE_BZIP2=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR_REL}"

.include <bsd.port.pre.mk>

FONTSDIR=	${PREFIX}/lib/X11/fonts/local
FONTSDIR_REL=	${FONTSDIR:S,^${PREFIX}/,,}

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

do-build:
	@${ECHO_CMD} -n 'Compressing PCF fonts'
.for i in ${FONTNAMES}
	@${ECHO_CMD} -n '.'
	@cd ${WRKSRC}; bdftopcf bdf/${i}.bdf | ${GZIP_CMD} > ${i}.pcf.gz
.endfor
	@${ECHO_CMD} 'Done'

pre-su-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${DOCSDIR}
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
# Do not use original install target since it forces to delete fonts.alias
.for i in ${FONTNAMES}
	${INSTALL_DATA} ${WRKSRC}/${i}.pcf.gz ${FONTSDIR}
.endfor
	@mkfontdir ${FONTSDIR}
	@${CAT} ${DOCSDIR}/fonts.alias >> ${FONTSDIR}/fonts.alias
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
