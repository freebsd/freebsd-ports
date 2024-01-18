# Infrastructure used by x11-fonts/noto-* ports.
#
# Feature:      noto
# Usage:        USES=noto
#
# The following variables can be defined in a port Makefile:
#
# NOTONAME	Name of the font, e.g. NotoSans.
# NOTOTAG	Git tag used in default NOTOLICSITES and NOTOSITES.
#		Default: ${NOTONAME}-v${PORTVERSION}.
# NOTOLICSITES	Location(s) of the license file.  Optional.
# NOTOSITES	Location(s) of the fonts.  Optional.
# NOTOLICFILE	Name of the license file.  Default: LICENSE.
# NOTOSTYLES	List of styles.  You can define this if the upstream font
#		files are named NOTONAME-STYLE.ttf.  Define NOTOFILES
#		directly if that's not the case.
# NOTOFILES	List of upstream font files and their style.  They will be
#		installed as NOTONAME-STYLE.ttf.  See x11-fonts/noto-emoji.
#		Default: derived from NOTOSTYLES.
#
# MAINTAINER:   tijl@FreeBSD.org

.if !defined(_INCLUDE_USES_NOTO_MK)
_INCLUDE_USES_NOTO_MK=	yes

EXTRACT_SUFX=	.tar.xz

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/${NOTOLICFILE}

FONTSDIR=	${PREFIX}/share/fonts/noto

NOTOTAG?=	${NOTONAME}-v${PORTVERSION}
NOTOLICSITES?=	https://github.com/notofonts/notofonts.github.io/raw/${NOTOTAG}/fonts/
NOTOSITES?=	https://github.com/notofonts/notofonts.github.io/raw/${NOTOTAG}/fonts/${NOTONAME}/hinted/ttf/
NOTOLICFILE?=	LICENSE
NOTOFILES?=	${NOTOSTYLES:C,.*,${NOTONAME}-&.ttf &,}
PLIST_FILES=	${NOTOFILES:N*.ttf:C,.*,${FONTSDIR:S,^${PREFIX}/,,}/${NOTONAME}-&.ttf,}

NO_ARCH=	yes
NO_BUILD=	yes

.  ifdef NO_CHECKSUM && DISABLE_SIZE && !DIST_SUBDIR
# Assume make fetch called from make makesum.
_USES_fetch+=	250:noto-fetch
.  endif

noto-fetch:
	@${MAKE} fetch NO_CHECKSUM=yes DISABLE_SIZE=yes \
		DISTFILES='${NOTOLICFILE}:lic ${NOTOFILES:M*.ttf}' \
		DIST_SUBDIR='${DISTNAME}' \
		MASTER_SITES='${NOTOLICSITES:S/$/:lic/} ${NOTOSITES}'
	@${ECHO_MSG} '===> Creating distfile ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}'
	@cd ${DISTDIR} && ${RM} ${DISTNAME}${EXTRACT_SUFX} && set -- \
		${NOTOLICFILE:S,^,${DISTNAME}/,} \
		${NOTOFILES:M*.ttf:S,^,${DISTNAME}/,} \
		&& ${CHMOD} 0644 "$$@" && ${CHMOD} 0755 ${DISTNAME} \
		&& ${TOUCH} -c -d 1970-01-01T00:00:00Z "$$@" ${DISTNAME} \
		&& ${TAR} cJf ${DISTNAME}${EXTRACT_SUFX} \
			--uid 0 --gid 0 --numeric-owner "$$@" \
		&& ${RM} "$$@" && { ${RMDIR} ${DISTNAME} 2>/dev/null || :; }

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.  for font style in ${NOTOFILES}
	${INSTALL_DATA} ${WRKSRC}/${font} \
		${STAGEDIR}${FONTSDIR}/${NOTONAME}-${style}.ttf
.  endfor

.include "${USESDIR}/fonts.mk"
.endif
