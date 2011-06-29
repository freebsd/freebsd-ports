# New ports collection makefile for:	rubygem-objectdetect
# Date created:		2008-11-25
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	objectdetect
PORTVERSION=	0.0.3
PORTREVISION=	5
CATEGORIES=	graphics rubygems
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mm
DISTFILES=	${PORTNAME}-${PORTVERSION}-opencv23.gem

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A simple library for detecting objects in pictures

LIB_DEPENDS=	opencv_legacy.2:${PORTSDIR}/graphics/opencv

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.include <bsd.port.post.mk>
