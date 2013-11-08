# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/esound/Makefile,v 1.1 2008/11/20 19:38:24 marcus Exp $

PORTNAME=	esound
PORTVERSION=	0.2.41
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for enlightenment package

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		pathfix pkgconfig:both
USE_LDCONFIG=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	JW=false

CONFLICTS=	py*-ro-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|esdconf_DATA = esd.conf|esdconf_DATA = |g' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/esd.conf ${STAGEDIR}${PREFIX}/etc/esd.conf.default
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libesd*.so.2

.include <bsd.port.mk>
