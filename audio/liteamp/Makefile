# New ports collection makefile for:	liteamp
# Date created:		24 June 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	liteamp
PORTVERSION=	0.2.4.2
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	http://kldp.net/frs/download.php/1153/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight Music Player for GNOME2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		ao.4:${PORTSDIR}/audio/libao \
		mad.2:${PORTSDIR}/audio/libmad \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis

USE_GNOME=	gnomehack libgnomeui
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

MAN1=		liteamp.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/-DGLADE_DIR/s|\\$$|| ; \
		 /-DG.*_DISABLE_DEPRECATED/d' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
