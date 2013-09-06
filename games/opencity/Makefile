# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	opencity
PORTVERSION=	0.0.6.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+)\..*$/\1/}/
DISTNAME=	${PORTNAME}-${PORTVERSION}stable

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D city simulator

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_SDL=	sdl mixer image net
USE_GL=		gl glu
USE_GCC=	any

PORTDOCS=	*

MAN6=		opencity.6

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
post-patch:
	@${REINPLACE_CMD} -e '/install-data-am/ s|install-docsDATA||' \
		${WRKSRC}/docs/Makefile.in
.endif

.include <bsd.port.mk>
