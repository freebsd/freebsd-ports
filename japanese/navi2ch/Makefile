# New ports collection makefile for:	navi2ch for emacs21
# Date created:		23 Nov 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../navi2ch-emacs20

EMACS_PORT_NAME=	emacs21

.if !defined(WITHOUT_X11)
RUN_DEPENDS=		${X11BASE}/lib/X11/fonts/local/monak12.pcf.gz:${PORTSDIR}/japanese/monafonts
.endif

.include "${MASTERDIR}/Makefile"
