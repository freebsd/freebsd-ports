# New ports collection makefile for:	navi2ch for xemacs21-mule
# Date created:		13 May 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../navi2ch-emacs20

EMACS_PORT_NAME=	xemacs21-mule

BUILD_DEPENDS=		${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.xemacs-base:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS=		${X11BASE}/lib/X11/fonts/local/monak12.pcf.gz:${PORTSDIR}/japanese/monafonts \
			${BUILD_DEPENDS}

.include "${MASTERDIR}/Makefile"
