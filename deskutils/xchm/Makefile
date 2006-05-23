# New ports collection makefile for:	xchm
# Date created:				3th October 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	xchm
PORTVERSION=	1.8
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Windows HTML Help (.chm) viewer for UNIX

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib \
		wx_baseu-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2u-2.6-config
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|@REZ_COMMAND@||' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
