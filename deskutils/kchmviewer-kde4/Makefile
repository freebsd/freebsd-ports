# New ports collection makefile for:	kchmviewer
# Date created:				Mon Jul 25 10:42:16 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kchmviewer
PORTVERSION=	2.5
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A Qt/KDE viewer for CHM files

LIB_DEPENDS+=	chm:${PORTSDIR}/misc/chmlib

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
DO_NOT_COMPILE+=chmlib
CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS}" DO_NOT_COMPILE="${DO_NOT_COMPILE}"

.if !defined(WITHOUT_KDE)
USE_KDELIBS_VER=3
PLIST_SUB+=	KDE=""
CONFIGURE_ARGS+=--with-kde
.else
USE_QT_VER=	3
PLIST_SUB+=	KDE="@comment "
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
DO_NOT_COMPILE+=kio-msits
.endif

pre-everything::
.if !defined(WITHOUT_KDE)
	@${ECHO_MSG} "You can disable KDE support by defining WITHOUT_KDE."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
