# ex:ts=8
# Ports collection makefile for:  vim-small
# Version required:     	  5.3
# Date created:			  Fri Jun 25, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1999/07/15 22:45:47 mharo Exp $
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
