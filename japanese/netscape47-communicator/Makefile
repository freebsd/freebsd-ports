# New ports collection makefile for: Netscape browser with Japanese resources
# Date created:		13 Mar 1998
# Whom:			sada
#
# $FreeBSD$
#

MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		http://www.imasy.or.jp/~mistral/netscape/resource/
DISTNAME=	communicator-ja-euc-v475-export.generic-generic-generic

MASTERDIR=	${.CURDIR}/../netscape4-communicator
SUBMASTERDIR=	${.CURDIR}/../netscape${BROWSER_VER}-communicator
FILESDIR=	${SUBMASTERDIR}/files
PATCHDIR=	${SUBMASTERDIR}/files
PKGDIR=		${SUBMASTERDIR}
MD5_FILE=	${SUBMASTERDIR}/distinfo

BROWSER_VER=	47
BROWSER_VERSION?=	4.76
NETHELP=	nethelp-v47

.include "${MASTERDIR}/Makefile"
