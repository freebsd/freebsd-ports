# New ports collection makefile for:	esound
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/esound/Makefile,v 1.1 2008/11/20 19:38:24 marcus Exp $
#

PORTNAME=	esound
PORTVERSION=	0.2.41
CATEGORIES=	audio
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A sound library for enlightenment package

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GNOME=	gnometarget gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	JW=false

CONFLICTS=	py*-ro-[0-9]*

MAN1=	esd-config.1 esd.1 esdcat.1 esdctl.1 esddsp.1 esdfilt.1 esdloop.1 \
	esdmon.1 esdplay.1 esdrec.1 esdsample.1

post-patch:
	@${REINPLACE_CMD} -e 's|esdconf_DATA = esd.conf|esdconf_DATA = |g' \
		${WRKSRC}/Makefile.in

post-install:
	if [ ! -f ${PREFIX}/etc/esd.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/esd.conf ${PREFIX}/etc/esd.conf; \
		${INSTALL_DATA} ${WRKSRC}/esd.conf ${PREFIX}/etc/esd.conf.default; \
	else \
		${INSTALL_DATA} ${WRKSRC}/esd.conf ${PREFIX}/etc/esd.conf.default; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
