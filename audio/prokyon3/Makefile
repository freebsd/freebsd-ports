# New ports collection makefile for:           prokyon3
# Date created:                                11 November 2002
# Whom:                                        Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	prokyon3
PORTVERSION=	0.9.1.r1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Prokyon3 is a multithreaded MP3 manager and tag editor

BUILD_DEPENDS=	${X11BASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
LIB_DEPENDS=	id3-3.8:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=	--with-qtdir=${X11BASE} --with-id3-libs=${LOCALBASE}\
			--with-ogg-libs=${LOCALBASE} --with-vorbis-libs=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|-g -O2|${CFLAGS}|; s|-lqt-mt|-lqt-mt ${PTHREAD_LIBS}|' ${WRKSRC}/configure

.include <bsd.port.mk>
