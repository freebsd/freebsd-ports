# New ports collection makefile for:	kwebget
# Date created:				21 September 2001
# Whom:					David <ddavid_3@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	kwebget
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	ftp kde
MASTER_SITES=	http://www.kpage.de/download/
DIST_SUBDIR=	KDE

MAINTAINER=	erich@tacni.net
COMMENT=	A KDE frontend to wget

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_KDELIBS_VER=	3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes

CONFIGURE_TARGET=       --build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
