# New ports collection makefile for: w3 on Mule
# Version required:	2.2.26	
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.7 1998/12/01 03:06:21 asami Exp $
#

PKGNAME=	ja-w3-2.2.26
CATEGORIES=	japanese www elisp

# Don't RUN_DEPENDS on mule because we don't know which version the
# user would want.  We can't omit the BUILD_DEPENDS because it needs
# to byte-compile .el files.
BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule
RUN_DEPENDS=

EMACSCMD=	mule
ELISPDIR=	${PREFIX}/lib/mule/site-lisp

MASTERDIR=	${.CURDIR}/../../www/w3
PKGDIR=		${.CURDIR}/pkg

.include "${MASTERDIR}/Makefile"
