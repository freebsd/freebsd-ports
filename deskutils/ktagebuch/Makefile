# New ports collection makefile for:	ktagebuch
# Date created:			Mon Nov 17 15:37:28 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		ktagebuch
PORTVERSION=		0.72
PORTREVISION=	2
CATEGORIES=		deskutils kde
MASTER_SITES=		http://home.tiscali.de/rainerb/ktagebuch/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		A diary program for KDE 3

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes

CONFIGURE_ENV=		LDFLAGS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${RM} ${WRKSRC}/ktagebuch/library/ui/inserthtmldialog.cpp \
		${WRKSRC}/ktagebuch/library/ui/inserthtmldialog.h

.include <bsd.port.mk>
