# Created by: t.vanklaveren@student.utwente.nl
# $FreeBSD$

PORTNAME=	libvorbis
PORTVERSION=	1.3.4
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Audio compression codec library

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg

USES=		libtool pathfix tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE} \
		--disable-docs		# don't rebuild

OPTIONS_DEFINE=	DOCS

post-stage:
	${LN} -s libvorbis.so.0 ${STAGEDIR}${PREFIX}/lib/libvorbis.so.4
	${LN} -s libvorbisfile.so.3 ${STAGEDIR}${PREFIX}/lib/libvorbisfile.so.6

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
