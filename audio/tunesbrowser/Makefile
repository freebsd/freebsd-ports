# New ports collection makefile for:	tunesbrowser
# Date created:		2004-07-27
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	tunesbrowser
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://crazney.net/programs/itunes/files/

MAINTAINER=	ahze@ahze.net
COMMENT=	Gnome frontend DAAP client

LIB_DEPENDS=	opendaap.0:${PORTSDIR}/devel/libopendaap

USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_X_PREFIX=	yes
USE_GNOME=	libglade2 gstreamerplugins gnometarget gnomehack

DATADIR=	${PREFIX}/share/gnome/${PORTNAME}

PLIST_FILES=	bin/tunesbrowser \
		%%DATADIR%%/tunesbrowser.glade
PLIST_DIRS=	%%DATADIR%%

pre-everything::
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Warning: ${PORTNAME} is extremelly buggy, especially'
	@${ECHO_MSG} '===> on the FreeBSD 4.x branch, and may not run at all'
	@${ECHO_MSG} '===>'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tunesbrowser ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tunesbrowser.glade ${DATADIR}

.include <bsd.port.mk>
