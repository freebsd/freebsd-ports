# New ports collection makefile for:	kimdaba
# Date created:			Sat Dec 13 16:09:29 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kimdaba
PORTVERSION=		1.0.1
PORTREVISION=	1
CATEGORIES=		graphics kde
MASTER_SITES=		http://ktown.kde.org/kimdaba/download/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Image database for KDE

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${RM} ${PREFIX}/share/locale/xx/LC_MESSAGES/kimdaba.mo
	@${RMDIR} ${PREFIX}/share/locale/xx/LC_MESSAGES/
	@${RMDIR} ${PREFIX}/share/locale/xx/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
