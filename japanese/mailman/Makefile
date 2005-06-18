# New ports collection makefile for:	ja-mailman
# Date created:				21 Feb 2003
# Whom:					Sunagawa Koji <koj@ofug.net>
#
# $FreeBSD$
#

CATEGORIES=	japanese mail

MAINTAINER=	koj@ofug.net
COMMENT=	Japanized mailman which is a mailing list manager with a web front-end

MASTERDIR=	${.CURDIR}/../../mail/mailman

.undef		WITH_HTDIG

pre-configure::
	@ ${ECHO} "DEFAULT_SERVER_LANGUAGE = 'ja'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in

.include "${MASTERDIR}/Makefile"
