# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	gkrellkam
PORTVERSION=	0.3.4
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin that display thumbnails of periodically updated images

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

NO_LATEST_LINK=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_GNOME=	imlib
USE_GMAKE=	yes

MAN5=		gkrellkam-list.5
PLIST_FILES=	libexec/gkrellm/plugins/gkrellkam.so

NO_STAGE=	yes
do-install:
	@${INSTALL_DATA} ${WRKSRC}/gkrellkam.so \
		${PREFIX}/libexec/gkrellm/plugins
	@${INSTALL_MAN} ${WRKSRC}/gkrellkam-list.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
