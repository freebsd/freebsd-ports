# New ports collection makefile for:	ktagebuch
# Date created:			Mon Nov 17 15:37:28 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		ktagebuch
PORTVERSION=		0.73
CATEGORIES=		deskutils kde
MASTER_SITES=		http://www.theblessing.net/programming/${PORTNAME}/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		A diary program for KDE 3

LIB_DEPENDS=		sqlite3:${PORTSDIR}/databases/sqlite3

EXTRA_PATCHES=		${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
