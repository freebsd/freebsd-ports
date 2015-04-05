# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/linphone/plugins/sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

BROKEN=		Distfile size mismatch
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MEDIASTREAMER
OPTIONS_DEFAULT=	MEDIASTREAMER

MEDIASTREAMER_DESC=	Mediastreamer(linphone) support

OPTIONS_SUB=	yes
MEDIASTREAMER_LIB_DEPENDS=	libortp.so:${PORTSDIR}/net/ortp \
				libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MMEDIASTREAMER}
# If the option is disabled, force it to not build mediastreamer interface even if
# configure found the needed dependencies
pre-configure:
	@${REINPLACE_CMD} -e '/^@BUILD_MSBCG729_TRUE@/d' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
