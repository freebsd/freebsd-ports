# New ports collection makefile for:	ja-samba
# Date created:				8 Nov 2004
# Whom:					Timur Bakeyev <timur@gnu.org>
#
# $FreeBSD$
#

PORTVERSION=		3.0.35
PORTEPOCH=		1
CATEGORIES=		japanese net
PKGNAMEPREFIX=		ja-

PATCH_SITES=		http://dist.bsdlab.org/
PATCHFILES=		samba-${PORTVERSION}-i18n-20090712.bz2
PATCH_DIST_STRIP=	-p0

MAINTAINER=		kuriyama@FreeBSD.org
COMMENT=		Japanese Samba

CONFLICTS=		ja-samba-2.* samba-2.* samba-3.0.* sharity-light-1.*

SAMBA_PORT=		samba3

MASTERDIR=		${.CURDIR}/../../net/${SAMBA_PORT}
MD5_FILE=		${.CURDIR}/distinfo
DESCR=			${.CURDIR}/pkg-descr
PORTSCOUT=		limit:^3\.0\.\d+

# Maintainer's note:
#   Don't forget to test with WITH_ADS, WITH_QUOTAS,
#   WITH_PAM_SMBPASS for such users.

.include "${MASTERDIR}/Makefile"
