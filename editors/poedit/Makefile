# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gettext catalogs (.po files) editor

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2	\
		db${LIB_SUFFIX}:${PORTSDIR}/databases/db${WITH_BDB_VER}

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include/db${WITH_BDB_VER} \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		poedit.1

.if defined(WITH_BDB2) || defined(WITH_DB2)
WITH_BDB_VER=	2
.elif defined(WITH_BDB3) || defined(WITH_DB3)
WITH_BDB_VER=	3
.elif defined(WITH_BDB4) || defined(WITH_DB4)
WITH_BDB_VER=	4
.elif defined(WITH_BDB41) || defined(WITH_DB41)
WITH_BDB_VER=	41
.elif defined(WITH_BDB42) || defined(WITH_DB42)
WITH_BDB_VER=	42
LIB_SUFFIX=	-4.2
.elif defined(WITH_BDB43) || defined(WITH_DB43)
WITH_BDB_VER=	43
LIB_SUFFIX=	-4.3
.endif
WITH_BDB_VER?=	4
LIB_SUFFIX?=	${WITH_BDB_VER}

.if defined(WITH_WXGTK24)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
CONFIGURE_ARGS+=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config
.else
LIB_DEPENDS+=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26
CONFIGURE_ARGS+=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.6-config
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's/for version in .*;/for version in ${WITH_BDB_VER};/ ; \
		 s/-ldb-$$version/-ldb${LIB_SUFFIX}/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s/ install / /' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
