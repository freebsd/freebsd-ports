# New ports collection makefile for:	tunesbrowser
# Date created:		2004-07-27
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	tunesbrowser
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://craz.net/programs/itunes/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple iTunes-like music player

LIB_DEPENDS=	opendaap.0:${PORTSDIR}/devel/libopendaap

USE_BZIP2=	yes
USE_INC_LIBTOOL_VER=15
USE_X_PREFIX=	yes
USE_GNOME=	libglade2 gnometarget gnomehack gnomeprefix
USE_GSTREAMER=	mad

MAN1=		tunesbrowser.1

DATADIR=	${PREFIX}/share/gnome/${PORTNAME}

pre-everything::
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Warning: ${PORTNAME} is extremelly buggy, especially'
	@${ECHO_MSG} '===> on the FreeBSD 4.x branch, and may not run at all'
	@${ECHO_MSG} '===>'

.include <bsd.port.mk>
