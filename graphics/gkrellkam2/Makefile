# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gkrellkam
PORTVERSION=	2.0.0
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin that display thumbnails of periodically updated images

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake pkgconfig
LATEST_LINK=	gkrellkam2

MAN5=		gkrellkam-list.5
PLIST_FILES=	libexec/gkrellm2/plugins/gkrellkam2.so

MAKE_ENV+=	MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

NO_STAGE=	yes
.include <bsd.port.mk>
