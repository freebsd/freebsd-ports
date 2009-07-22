# New ports collection makefile for:	libygp
# Date created:		2 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	libYGP
PORTVERSION=	0.9.12
CATEGORIES=	devel
MASTER_SITES=	SF/libymp
DISTNAME=	libYGP-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another General Purpose library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --with-gmp\
		--disable-static --disable-rpath

.if ${PORTNAME:M*XGP}
LIB_DEPENDS+=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
PLIST_SUB=	YGP="@comment " XGP=""
CFG_PATCH=	s/mozembed/mozembedNO/g;
XGP_PATCH=	s/(^@AM.*)?GtkMozViewer(.lo|.c|.Plo@am__quote@)//;
MKIN_PATCH=	s/^(SUBDIRS = ).*$$/\1XGP/;
.else
PLIST_SUB=	XGP="@comment " YGP=""
MKIN_PATCH=	s/@MYSUBDIRS@/YGP/;
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test.*==/s|==|=|g;/LIBRELEASE=/s|=.*|=0|;${CFG_PATCH}' ${WRKSRC}/configure
	@${REINPLACE_CMD} -Ee '${XGP_PATCH}' ${WRKSRC}/XGP/Makefile.in
	@${REINPLACE_CMD} -Ee '/include_HEADERS/s|config.h||;${MKIN_PATCH}' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^#include/s|malloc.h|stdlib.h|' ${WRKSRC}/XGP/GTKViewer.c
	@${REINPLACE_CMD} -e '/^typedef int socklen_t;/d' ${WRKSRC}/YGP/Socket.cpp
	@${REINPLACE_CMD} -e '/^#.*define sleep/d' ${WRKSRC}/YGP/Tests/Thread.cpp
	@${REINPLACE_CMD} -e 's|SigC::Connection|sigc::connection|g' \
		${WRKSRC}/XGP/MessageDlg.h
.if ${PORTNAME:M*XGP}
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/ygp-cfg/xgp-cfg/g'
	@${CP} ${WRKSRC}/ygp-cfg.h ${WRKSRC}/xgp-cfg.h
	@${CP} ${WRKSRC}/ygp-cfg.h.in ${WRKSRC}/xgp-cfg.h.in
	@${REINPLACE_CMD} -e 's|libgtkhtml-3.8|libgtkhtml-3.14|g' \
	    	${WRKSRC}/configure
.endif

post-install:
	@${LN} -sf ${PREFIX}/lib/${PORTNAME}-0.so ${PREFIX}/lib/${PORTNAME}.so.0

.include <bsd.port.mk>
