# New ports collection makefile for:	lookup for XEmacs
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

BUILD_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.cookie:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.cookie:${PORTSDIR}/editors/xemacs-packages

MASTERDIR=	${.CURDIR}/../lookup
EMACS_PORT_NAME=xemacs21-mule

.if defined(PARALLEL_PACKAGE_BUILD)
IGNORE=	hang
.endif

.include	"${MASTERDIR}/Makefile"
