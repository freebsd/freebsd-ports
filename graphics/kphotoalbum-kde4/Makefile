# New ports collection makefile for:	kimdaba
# Date created:			Sat Dec 13 16:09:29 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kimdaba
PORTVERSION=		1.1
PORTREVISION=		2
CATEGORIES=		graphics kde
MASTER_SITES=		http://ktown.kde.org/kimdaba/download/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Image database for KDE

EXTRA_PATCHES=		${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's/xx//g' ${WRKSRC}/po/Makefile.in

.include <bsd.port.mk>
