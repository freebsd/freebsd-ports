# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	1.95.8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO='makeinfo --no-split'
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		gst.1

.if defined(WITH_TCLTK)
LIB_DEPENDS+=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.3 \
			--with-tk=${LOCALBASE}/lib/tk8.3
PLIST_SUB+=		TCLTK=""
.else
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=		TCLTK="@comment "
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/gst.info*

pre-patch:
	@find ${WRKSRC} -name 'Makefile.in' | xargs ${PERL} -pi -e \
		's| -release \$$\(VERSION\)| -avoid-version|g'
	@${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/libltdl/ltdl.c

.include <bsd.port.mk>
