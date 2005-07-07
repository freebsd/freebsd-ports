# New ports collection makefile for:	goom
# Date created:				12 February 2005
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goom
PORTVERSION=	2k4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|}-src

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Visual effects library

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S|.|-|}
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
USE_GCC=	3.4
USE_INC_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-sdltest --enable-static
INSTALLS_SHLIB=	yes

.if exists(${X11R6}/bin/xmms) || defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
PLIST_SUB+=	XMMS="@comment "
.endif

pre-everything::
.if !defined(WITH_XMMS)
	@${ECHO} ""
	@${ECHO} "Define WITH_XMMS to build goom xmms visualization plugin"
	@${ECHO} ""
.endif

patch-autotools:
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.mk>
