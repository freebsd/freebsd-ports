# New ports collection makefile for:    ja-linux_locale
# Date created:         March 20 2000
# Whom:                 imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	linux_locale
PORTVERSION=	${VERSION}.0
PORTREVISION=	2
CATEGORIES=	japanese emulators linux
MASTER_SITES=	ftp://ftp.debian.org/debian/dists/woody/main/source/admin/
DISTNAME=	locale-ja_${VERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Linux glibc 2.0/2.1 locale definition for Japanese

BUILD_DEPENDS=	${LCDEF_CMD}:${PORTSDIR}/emulators/linux_base

IGNORE=		"ja-linux_locale is not needed for linux_base7"

USE_LINUX_PREFIX=	yes
WRKSRC=		${WRKDIR}/locale-ja-${VERSION}
PLIST_SUB=	VER=${VERSION} LINUXBASE=${LINUXBASE}

VERSION=	18
SRCDEF=		${WRKSRC}/ja_JP
CHARMAPS=	${WRKSRC}/charmaps/EUC-JP
REPERTOIRE_MAP=	${LINUXBASE}/usr/share/i18n/repertoiremaps/charids.894
LCDEF_CMD=	${LINUXBASE}/usr/bin/localedef
LCDEF_ARGS=	--repertoire-map=${REPERTOIRE_MAP} \
		-c -f ${CHARMAPS} -i ${SRCDEF}
LCDIR=		${LINUXBASE}/usr/share/locale/ja_JP
COMPAT_LC=	${LINUXBASE}/usr/share/locale/ja_JP.EUC
DOCDIR=		${LINUXBASE}/usr/doc/locale-ja-${VERSION}

LOCALE_ADD=	ja_JP.EUC
LOCALE_DEF_ja_JP.EUC=	ja_JP.eucJP

.include <bsd.port.pre.mk>

LOCALE_GREP=	${GREP} -q
.for locale in ${LOCALE_ADD}
LOCALE_ALIASES!=	${ECHO_CMD} ${LOCALE_ALIASES} ${locale}:${LOCALE_DEF_${locale}}
LOCALE_GREP!=	${ECHO_CMD} "${LOCALE_GREP} -e '^${locale}'"
.endfor
PLIST_SUB+=	LOCALE_ALIASES="${LOCALE_ALIASES}" LOCALE_GREP="${LOCALE_GREP}"

do-build:
	${MKDIR} ${WRKDIR}/LC_MESSAGES
	${LCDEF_CMD} ${LCDEF_ARGS} ${WRKDIR}

do-install:
	${MKDIR} ${LCDIR}/LC_MESSAGES
.for LC in COLLATE CTYPE MONETARY NUMERIC TIME
	${INSTALL_DATA} ${WRKDIR}/LC_${LC} ${LCDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/LC_MESSAGES/SYS_LC_MESSAGES ${LCDIR}/LC_MESSAGES
	${LN} -sf ja_JP ${COMPAT_LC}
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/* ${DOCDIR}
	if [ ! -f ${LINUXBASE}/usr/share/locale/locale.alias.orig ]; then \
		${CP} -p ${LINUXBASE}/usr/share/locale/locale.alias \
			 ${LINUXBASE}/usr/share/locale/locale.alias.orig; \
	fi
.for locale in ${LOCALE_ADD}
	${GREP} -q -e ^${locale} ${LINUXBASE}/usr/share/locale/locale.alias \
	 || ${ECHO_CMD} "${locale}	${LOCALE_DEF_${locale}}" \
		>> ${LINUXBASE}/usr/share/locale/locale.alias
.endfor

.include <bsd.port.post.mk>
