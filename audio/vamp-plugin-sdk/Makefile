# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	vamp-plugin-sdk
PORTVERSION=	2.3
CATEGORIES=	audio
MASTER_SITES=	http://code.soundsoftware.ac.uk/attachments/download/224/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Vamp audio analysis plugin SDK

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
NO_STAGE=	yes
USES=		gmake pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
