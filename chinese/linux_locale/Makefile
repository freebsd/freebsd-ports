# New ports collection makefile for:    zh-linux_locale
# Date created:         01/09/29
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux_locale
PORTVERSION=	${VERSION:S/+/./}
CATEGORIES=	chinese emulators linux
MASTER_SITES=	ftp://ftp.jp.debian.org/debian/dists/potato/main/source/admin/
DISTNAME=	locale-zh_${VERSION}.orig

PATCH_SITES=    ${MASTER_SITES}
PATCHFILES=     locale-zh_${VERSION}-${PATCHLEVEL}.diff.gz
PATCH_DIST_STRIP=-p1
MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	${LCDEF_CMD}:${PORTSDIR}/emulators/linux_base

USE_LINUX_PREFIX=	yes
WRKSRC=		${WRKDIR}/zh-localedata-${VERSION:C/\\+.*//}
PLIST_SUB=	VER=${VERSION}

VERSION=	0.9+0.05
PATCHLEVEL=     5
REPERTOIRE_MAP=	${LINUXBASE}/usr/share/i18n/repertoiremaps/mnemonic.ds
LCDEF_CMD=	${LINUXBASE}/usr/bin/localedef
TLCDEF_ARGS=	--repertoire-map=${REPERTOIRE_MAP} \
		-c -f ./BIG5_1984 -i ./zh_TW.Big5
CLCDEF_ARGS=	--repertoire-map=${REPERTOIRE_MAP} \
		-c -f ./GB2312 -i ./zh_CN.GB2312
TLCDIR=		${PREFIX}/usr/share/locale/zh_TW.Big5
CLCDIR=		${PREFIX}/usr/share/locale/zh_CN.GB2312
DOCDIR=		${PREFIX}/usr/doc/locale-zh-${VERSION}

post-patch:
	${RM} -f ${WRKSRC}/debian/*.orig 

do-build:
	cd ${WRKSRC}/zh_TW.Big5; ${LCDEF_CMD} ${TLCDEF_ARGS} ${WRKDIR}/zh_TW.Big5
	cd ${WRKSRC}/zh_CN.GB2312; ${LCDEF_CMD} ${CLCDEF_ARGS} ${WRKDIR}/zh_CN.GB2312

do-install:
	${MKDIR} ${TLCDIR}/LC_MESSAGES
	${MKDIR} ${CLCDIR}/LC_MESSAGES
.for LC in COLLATE CTYPE MONETARY NUMERIC TIME
	${INSTALL_DATA} ${WRKDIR}/zh_TW.Big5/LC_${LC} ${TLCDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/zh_TW.Big5/LC_MESSAGES/SYS_LC_MESSAGES ${TLCDIR}/LC_MESSAGES
.for LC in COLLATE CTYPE MONETARY NUMERIC TIME
	${INSTALL_DATA} ${WRKDIR}/zh_CN.GB2312/LC_${LC} ${CLCDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/zh_CN.GB2312/LC_MESSAGES/SYS_LC_MESSAGES ${CLCDIR}/LC_MESSAGES
	${LN} -sf zh_TW.Big5 ${PREFIX}/usr/share/locale/zh_TW
	${LN} -sf zh_CN.GB2312 ${PREFIX}/usr/share/locale/zh_CN
	${LN} -sf zh_CN.GB2312 ${PREFIX}/usr/share/locale/zh
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/* ${DOCDIR}

.include <bsd.port.mk>
