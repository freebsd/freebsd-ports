# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.1.10
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3 \
		intl.4:${PORTSDIR}/devel/gettext \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include/db3 -I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=	poedit.1

post-patch:
	@${REINPLACE_CMD} -e 's|db-3.1;|db-3.1 db3;|g ; \
		 s|-O3||g' ${WRKSRC}/configure

.include <bsd.port.mk>
