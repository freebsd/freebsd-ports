# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	xmms-liveice
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/
DISTNAME=	liveice-xmms

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use XMMS for streaming audio to Icecast servers

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

WRKSRC=		${WRKDIR}/LiveIce-${PORTVERSION}

PLIST_FILES=	lib/xmms/Effect/libliveice.la \
		lib/xmms/Effect/libliveice.so
USE_LDCONFIG=	yes
NO_STAGE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
