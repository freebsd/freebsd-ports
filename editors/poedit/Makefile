# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.2.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	gettext catalogs (.po files) editor

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3 \
		intl.5:${PORTSDIR}/devel/gettext \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CPPFLAGS=	-I${LOCALBASE}/include/db3 -I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		poedit.1

post-patch:
	@${REINPLACE_CMD} -e 's|db-3.1;|db-3.1 db3;|g ; \
		 s|-O3||g' ${WRKSRC}/configure

.include <bsd.port.mk>
