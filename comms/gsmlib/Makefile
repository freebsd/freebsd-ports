# ex:ts=8
# Ports collection makefile for:	gsmlib
# Date created:			Apr 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsmlib
PORTVERSION=	1.10
PORTREVISION=	5
CATEGORIES=	comms
MASTER_SITES=	DEBIAN
#TODO: examine the Debian patches, and changes in the Mandrake
#gsmlib-1.11-0.2mdv2007.0.src.rpm, for use in this port
DISTFILES=	gsmlib_1.10.orig.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library to access GSM mobile phones through GSM modems

USE_GNOME=	lthack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=	gsmctl.1 gsmpb.1 gsmsendsms.1 gsmsmsstore.1
MAN7=	gsminfo.7
MAN8=	gsmsmsd.8

CPPFLAGS+=	-I${LOCALBASE}/include -DBROKEN_STRFTIME -DHAVE_DECL_GETOPT \
		${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

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
