# New ports collection makefile for:	ja-tcsh NLS catalog (Multi)
# Version required:	6.08.02
# Date created:		19 August 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/12/01 03:06:20 asami Exp $
#

DISTNAME=	tcsh-6.08.02.add2
PKGNAME=	ja-tcsh-nls-multi-6.08.02
CATEGORIES=	japanese shells
MASTER_SITES=	http://www2.wbs.ne.jp/~znc/tcsh/

MAINTAINER=	issei@jp.FreeBSD.ORG

MASTERDIR=	${.CURDIR}/../tcsh-nls-generic
PKGDIR=		${.CURDIR}/pkg
PLIST=		${MASTERDIR}/pkg/PLIST
NLSSRC=		${DISTNAME}/nls/ja.multi

.include	"${MASTERDIR}/Makefile"
