# New ports collection makefile for:	ja-mailman
# Date created:				21 Feb 2003
# Whom:					Sunagawa Koji <koj@ofug.net>
#
# $FreeBSD$
#

CATEGORIES=	japanese mail

PATCH_SITES=	http://mm.tkikuchi.net/:japanese
PATCHFILES=	mailman-${PORTVERSION}+patch.20040516.gz:japanese

MAINTAINER=	koj@ofug.net
COMMENT=	Japanized mailman which is a mailing list manager with a web front-end

BROKEN=		"was not updated to 2.1.6 yet"

MASTERDIR=	${.CURDIR}/../../mail/mailman
MD5_FILE=	${.CURDIR}/distinfo

.undef		WITH_HTDIG

pre-configure::
	@ ${ECHO} "DEFAULT_SERVER_LANGUAGE = 'ja'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in

.include "${MASTERDIR}/Makefile"
