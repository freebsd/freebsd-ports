# New ports collection makefile for:	PCB
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	pcb
PORTVERSION=	20060822
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

.if defined(WITH_MOTIF_GUI)
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-gui=lesstif
.else
USE_GNOME=	gtk20
.endif
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_TK_RUN=	83
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

.if !defined(NOPORTDOCS)
INFO=		pcb
MAN1=		pcb.1
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.include <bsd.port.mk>
