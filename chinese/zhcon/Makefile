# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	statue@freebsd.sinica.edu.tw

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-included-gettext=${LOCALBASE}
USE_GMAKE=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS= # empty
USE_XLIB=	yes

MAN1=		zhcon.1

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} > 500012
.for i in src/main.cpp src/zhcon.cpp src/inputmanager.cpp src/display/fbdev.cpp src/mouse.h
	${REINPLACE_CMD} 's,machine/console.h>,sys/consio.h>@#include <sys/fbio.h>@#include <sys/kbio.h>,' ${WRKSRC}/${i} | tr '@' '\n' > ${WRKSRC}/${i}.bak && \
	${MV} ${WRKSRC}/${i}.bak ${WRKSRC}/${i}
.endfor
	${REINPLACE_CMD} -i.bak -e 's,machine/mouse.h>,sys/mouse.h>,' ${WRKSRC}/src/mouse.h
.endif

.include <bsd.port.post.mk>
