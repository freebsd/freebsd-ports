# New ports collection makefile for:    ja-linux_locale
# Version required:	13
# Date created:         March 20 2000
# Whom:                 imura@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	locale-ja_${VERSION}
PKGNAME=	ja-linux_locale-13.0
CATEGORIES=	japanese emulators linux
MASTER_SITES=	ftp://ftp.debian.org/debian/dists/potato/main/source/admin/ \
		http://people.FreeBSD.org/~imura/distfiles/

MAINTAINER=	imura@FreeBSD.org

BUILD_DEPENDS=	${LCDEF_CMD}:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	${LINUX_BASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

LINUX_BASE=	/compat/linux
PREFIX=		${LINUX_BASE}
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/locale-ja-${VERSION}
PLIST_SUB=	VER=${VERSION}

VERSION=	13
SRCDEF=		${WRKSRC}/ja_JP
CHARMAPS=	${WRKSRC}/charmaps/EUC-JP
REPERTOIRE_MAP=	${LINUX_BASE}/usr/share/i18n/repertoiremaps/charids.894
LCDEF_CMD=	${LINUX_BASE}/usr/bin/localedef
LCDEF_ARGS=	--repertoire-map=${REPERTOIRE_MAP} \
		-c -f ${CHARMAPS} -i ${SRCDEF}
LCDIR=		${PREFIX}/usr/share/locale/ja_JP
COMPAT_LC=	${PREFIX}/usr/share/locale/ja_JP.EUC
DOCDIR=		${PREFIX}/usr/doc/locale-ja-${VERSION}

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

.include <bsd.port.mk>
