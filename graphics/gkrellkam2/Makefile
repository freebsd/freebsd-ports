# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gkrellkam
PORTVERSION=	2.0.0
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTVERSION}
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin that display thumbnails of periodically updated images

LICENSE=	GPLv2+

BUILD_DEPENDS=	gkrellm2>0:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm2>0:sysutils/gkrellm2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake pkgconfig

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellkam2.so \
		man/man5/gkrellkam-list.5.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|$$(CC)|' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	(cd ${WRKSRC} && ${INSTALL_LIB} gkrellkam2.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins)
	(cd ${WRKSRC} && ${INSTALL_MAN} gkrellkam-list.5 \
		${STAGEDIR}${MAN5PREFIX}/man/man5)

.include <bsd.port.mk>
