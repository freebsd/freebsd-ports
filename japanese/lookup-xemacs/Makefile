# New ports collection makefile for:	lookup for XEmacs
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

BUILD_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.cookie:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.cookie:${PORTSDIR}/editors/xemacs-packages

MASTERDIR=	${.CURDIR}/../lookup
USE_EMACS=	yes
EMACS_PORT_NAME=xemacs21-mule

BROKEN=		Does not install
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

.include	"${MASTERDIR}/Makefile"
