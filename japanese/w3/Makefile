# New ports collection makefile for: w3 on Mule
# Version required:	2.2.26	
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.5 1997/09/14 21:36:20 max Exp $
#

PKGNAME=	ja-w3-2.2.26
CATEGORIES=	www japanese elisp
FILESDIR=	${.CURDIR}/../../www/w3/files
PATCHDIR=	${.CURDIR}/../../www/w3/patches

# Don't RUN_DEPENDS on mule because we don't know which version the
# user would want.  We can't omit the BUILD_DEPENDS because it needs
# to byte-compile .el files.
BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule
RUN_DEPENDS=

EMACSCMD=	mule
ELISPDIR=	${PREFIX}/lib/mule/site-lisp

.include "${.CURDIR}/../../www/w3/Makefile"
