# New ports collection makefile for:   tta
# Date created:        10 Aug 2004
# Whom:                dieringe
#
# $FreeBSD$
#

PORTNAME=		tta
PORTVERSION=		3.2
CATEGORIES=		audio
MASTER_SITES=		http://www.true-audio.com/ftp/
DISTNAME=		${PORTNAME}enc-${PORTVERSION}-src

MAINTAINER=		dieringe@zedat.fu-berlin.de
COMMENT=		"The True Audio Encoder", lossless (de)compressor

USE_ZIP=		yes
USE_GMAKE=		yes
WRKSRC=			${WRKDIR}
ALL_TARGET=

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Requires FreeBSD 5.x or higher for wide character support
.endif

.include <bsd.port.post.mk>
