# New ports collection makefile for:	kasablanca
# Date created:			Fri Apr 16 12:10:00 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kasablanca
PORTVERSION=	0.3.1
CATEGORIES=	ftp kde
MASTER_SITES=	http://download.berlios.de/kasablanca/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical ftp client for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-extract:
	@${CP} ${FILESDIR}/subdirs ${WRKSRC}
	@${TOUCH} -t 200404152151 ${WRKSRC}/subdirs

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|\(-lssl\)|\1 -lcrypto|' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/kbftp/Makefile.in

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
