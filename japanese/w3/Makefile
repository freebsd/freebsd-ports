# New ports collection makefile for: w3 on Mule
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

COMMENT=	WWW browser based on emacs/mule
CATEGORIES=	japanese

# Don't RUN_DEPENDS on mule because we don't know which version the
# user would want.  We can't omit the BUILD_DEPENDS because it needs
# to byte-compile .el files.
BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule
RUN_DEPENDS=	# none

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

EMACSCMD=	mule
ELISPDIR=	${PREFIX}/lib/mule/site-lisp

MASTERDIR=	${.CURDIR}/../../www/w3
PKGDIR=		${.CURDIR}

.include "${MASTERDIR}/Makefile"
