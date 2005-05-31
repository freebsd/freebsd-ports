# ex:ts=8
# Ports collection makefile for:	gsmlib
# Date created:			Apr 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsmlib
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library to access GSM mobile phones through GSM modems

USE_GNOME=	gnometarget lthack
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=	gsmctl.1 gsmpb.1 gsmsendsms.1 gsmsmsstore.1
MAN7=	gsminfo.7
MAN8=	gsmsmsd.8

CPPFLAGS=	-I${LOCALBASE}/include -DBROKEN_STRFTIME -DHAVE_DECL_GETOPT \
			${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${GREP} -lR "<malloc.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

.include <bsd.port.mk>
