# New ports collection makefile for:    ja-squirrelmail
# Date Created:                 17 Oct 2003
# Whom:                         Masafumi Otsune <info@otsune.com>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail
PORTVERSION=	1.4.5
PORTREVISION=	0
PORTEPOCH=	2
CATEGORIES=	japanese mail www

PATCH_SITES=	http://www.yamaai-tech.com/~masato/Download/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-ja-${PATCHVERSION}-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	info@otsune.com
COMMENT=	A webmail system which accesses mail over IMAP with Japanese patch

#BROKEN=	ja patch is not applied.

USE_GETTEXT=	YES

CONFLICTS=	squirrelmail-1.*
PATCHVERSION=	20050714

MASTERDIR=	${.CURDIR}/../../mail/squirrelmail
MD5_FILE=	${.CURDIR}/distinfo

slaveport-post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

.include "${MASTERDIR}/Makefile"
