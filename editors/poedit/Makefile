# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gettext catalogs (.po files) editor

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2 \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config

CPPFLAGS=	-I${LOCALBASE}/include/db${USE_BDB_VER} \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		poedit.1

.if defined(WITH_BDB_VER)
USE_BDB_VER=	${WITH_BDB_VER}
.else
USE_BDB_VER=	3
.endif

.if ${USE_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
.elif ${USE_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.elif ${USE_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
.else
BROKEN=		"WITH_BDB_VER must be 3, 4 or 41"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's/for version in .*;/for version in ${USE_BDB_VER};/ ; \
		 s/-ldb-$$version/-ldb${USE_BDB_VER}/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s/ install / /' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
