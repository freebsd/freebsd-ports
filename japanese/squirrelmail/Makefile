# New ports collection makefile for:    ja-squirrelmail
# Date Created:                 17 Oct 2003
# Whom:                         Masafumi Otsune <info@otsune.com>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail
PORTVERSION=	1.4.3a
PORTREVISION=	5
PORTEPOCH=	2
CATEGORIES=	japanese mail www

PATCH_SITES=	http://www.yamaai-tech.com/~masato/Download/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-ja-${PATCHVERSION}-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	info@otsune.com
COMMENT=	A webmail system which accesses mail over IMAP with Japanese patch

BROKEN=		Distinfo out of date

USE_GETTEXT=	YES

CONFLICTS=	squirrelmail-1.*
PATCHVERSION=	20041014

MASTERDIR=	${.CURDIR}/../../mail/squirrelmail
MD5_FILE=	${.CURDIR}/distinfo

slaveport-post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-build:
	@cd ${WRKSRC}/po && ./compilepo ja_JP

.include "${MASTERDIR}/Makefile"
