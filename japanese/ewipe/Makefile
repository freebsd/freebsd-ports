# New ports collection makefile for:	ewipe
# Version required:	1.0.0
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.11 1998/03/04 06:18:54 itojun Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../misc/ewipe/files
PKGDIR=		${.CURDIR}/../../misc/ewipe/pkg
SCRIPTDIR=	${.CURDIR}/../../misc/ewipe/scripts
COMMENT=	${.CURDIR}/pkg/COMMENT

PKGNAME=	ja-ewipe-1.0.0
KANJI=		yes

.include <${.CURDIR}/../../misc/ewipe/Makefile>

CATEGORIES=	japanese misc tk42

MAINTAINER=	itojun@itojun.org

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42
