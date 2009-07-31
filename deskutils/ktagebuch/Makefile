# New ports collection makefile for:	ktagebuch
# Date created:			Mon Nov 17 15:37:28 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		ktagebuch
PORTVERSION=		0.74
PORTREVISION=	6
CATEGORIES=		deskutils kde
MASTER_SITES=		http://www.theblessing.net/programming/${PORTNAME}/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A diary program for KDE 3

LIB_DEPENDS=		sqlite3:${PORTSDIR}/databases/sqlite3

EXTRA_PATCHES=		${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
USE_LDCONFIG=		yes
INSTALLS_ICONS=		yes
USE_GETTEXT=		yes

CONFIGURE_ARGS+=	--with-sqlite \
			--with-sqlite-incdir=${LOCALBASE}/include \
			--with-sqlite-libdir=${LOCALBASE}/lib

DOCSDIR=	share/doc/HTML

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
