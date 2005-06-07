# New ports collection makefile for:	esound
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.2.36
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://cvs.gnome.org/viewcvs/esound/:arts
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.if defined(WITH_ARTS)
DISTFILES+=	${ARTS_FILE}:arts
.endif
DIST_SUBDIR=	gnome
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A sound library for enlightenment package

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

ARTS_FILE=	audio_arts.c?rev=1.1

USE_BZIP2=	yes
USE_GNOME=	gnometarget gnomehack
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GETOPT_LONG=yes

CONFLICTS=	py*-ro-[0-9]*

MAN1=	esd-config.1 esd.1 esdcat.1 esdctl.1 esddsp.1 esdfilt.1 esdloop.1 \
	esdmon.1 esdplay.1 esdrec.1 esdsample.1

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts

CONFIGURE_ARGS+=--enable-arts
.else
CONFIGURE_ARGS+=--disable-arts
.endif

pre-everything::
.if !defined(WITH_ARTS)
	@${ECHO_MSG} "You can enable audio/arts backend by defining"
	@${ECHO_MSG} "WITH_ARTS"
	@${ECHO_MSG} ""
.endif

post-patch:
.if defined(WITH_ARTS)
	@${CP} ${_DISTDIR}/${ARTS_FILE} ${WRKSRC}/audio_arts.c
.endif
	@${REINPLACE_CMD} -e 's|esdconf_DATA = esd.conf|esdconf_DATA = |g' \
		${WRKSRC}/Makefile.in

post-install:
	if [ ! -f ${PREFIX}/etc/esd.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/esd.conf ${PREFIX}/etc/esd.conf; \
		${INSTALL_DATA} ${WRKSRC}/esd.conf ${PREFIX}/etc/esd.conf.default; \
	else \
		${INSTALL_DATA} ${WRKSRC}/esd.conf ${PREFIX}/etc/esd.conf.default; \
	fi

.include <bsd.port.mk>
