# New ports collection makefile for:	fbbi
# Date created:        22 December 2001
# Whom:                Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	fbbi
PORTVERSION=	2003.0326
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www3.telus.net/public/cpressey/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org
COMMENT=	An interpreter for the Befunge-98 language

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/../bin/fbbi ${PREFIX}/bin

.include <bsd.port.mk>
