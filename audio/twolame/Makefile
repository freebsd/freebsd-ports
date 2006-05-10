# New ports collection makefile for:	twolame
# Date created:		2005-05-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twolame
PORTVERSION=	0.3.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.ecs.soton.ac.uk/~njh/twolame/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	MPEG Audio Layer 2 encoder

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget
INSTALLS_SHLIB=	yes
MAN1=		twolame.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Incorrect plist
.endif

.include <bsd.port.post.mk>
