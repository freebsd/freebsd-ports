# New ports collection makefile for:	gkrellkam
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellkam
PORTVERSION=	0.3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_IMLIB=	yes
USE_GMAKE=	yes

MAN5=		gkrellkam-list.5

do-install:
	@${INSTALL_DATA} ${WRKSRC}/gkrellkam.so \
		${PREFIX}/libexec/gkrellm/plugins
	@${INSTALL_MAN} ${WRKSRC}/gkrellkam-list.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
