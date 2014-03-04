# Created by: Jan Srzednicki <w@wrzask.pl>
# $FreeBSD$

PORTNAME=	gkrellmoon2
PORTVERSION=	0.6
PORTREVISION=	9
CATEGORIES=	astro
MASTER_SITES=	SF/gkrellmoon/gkrellmoon/${PORTVERSION}
DISTNAME=	gkrellmoon-${PORTVERSION}

MAINTAINER=	w@wrzask.pl
COMMENT=	Moon clock plugin for Gkrellm2

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USES=		pkgconfig
USE_GNOME=	gtk20

ALL_TARGET=	gkrellmoon.so

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_DATA} ${WRKSRC}/gkrellmoon.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
