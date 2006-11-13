# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/editors/poedit/Makefile,v 1.2 2006/10/05 07:03:09 mezz Exp $
#

PORTNAME=	poedit
PORTVERSION=	1.3.6
PORTREVISION=	0
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gettext catalogs (.po files) editor

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		wx_gtk2u_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-unicode

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_BDB=	yes
WITH_BDB_HIGHEST=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		WXRC="${X11BASE}/bin/wxrc-gtk2u-2.6"
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2u-2.6-config \
		--mandir=${MANPREFIX}/man

CPPFLAGS=	-I${BDB_INCLUDE_DIR} \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${BDB_LIB_DIR} ${PTHREAD_LIBS}

MAN1=		poedit.1

post-patch:
	@${REINPLACE_CMD} -e \
		's/for version in .*;/for version in ${BDB_VER};/ ; \
		 s/-ldb-$$version/-l${BDB_LIB_NAME}/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s/ install / /' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
