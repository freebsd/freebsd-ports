# New ports collection makefile for:	ewipe
# Version required:	0.7.0
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.10 1998/02/22 08:35:01 fenner Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../misc/ewipe/files
PKGDIR=		${.CURDIR}/../../misc/ewipe/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

PKGNAME=	ja-ewipe-0.7.0

.include <${.CURDIR}/../../misc/ewipe/Makefile>

CATEGORIES=	japanese misc tk42

MAINTAINER=	itojun@itojun.org

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42
