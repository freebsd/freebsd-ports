# ex:ts=8
# Ports collection makefile for:  vim-lite
# Version required:     	  5.3
# Date created:			  Fri Jun 25, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PKGNAME=	vim-lite-5.3

LITE=		yes

.include <bsd.port.pre.mk>
.if exists(${.CURDIR}/../vim5)
MASTERDIR=	${.CURDIR}/../vim5
.else
MASTERDIR=	${PORTSDIR}/editors/vim5
.endif

.include "${MASTERDIR}/Makefile"
