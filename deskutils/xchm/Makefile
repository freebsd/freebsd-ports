# New ports collection makefile for:	xchm
# Date created:				3th October 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	xchm
PORTVERSION=	0.8.4
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@oook.cz
COMMENT=	Windows HTML Help (.chm) viewer for UNIX

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel \
		chm.0:${PORTSDIR}/misc/chmlib

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@REZ_COMMAND@||' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
