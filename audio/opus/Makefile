# $FreeBSD$

PORTNAME=	opus
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	opus

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	IETF audio codec

USES=		gmake libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-custom-modes \
		--disable-maintainer-mode \
		--disable-doc   # requires doxygen

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
CONFIGURE_ARGS+=--enable-fixed-point
.endif

.include <bsd.port.mk>
