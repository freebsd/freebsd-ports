# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzvbi
PORTVERSION=	0.2.35
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/zapping/zvbi/${PORTVERSION}
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Routines to access raw VBI capture devices

LICENSE=	GPLv2+

LIB_DEPENDS+=	libpng.so:graphics/png \
		libunicode.so:devel/libunicode

USES=		iconv libtool localbase pathfix tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-doxygen
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=nls
NLS_USES=	gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's|#cpu (\([^)]*\))|defined(__\1__)|g' \
		${WRKSRC}/src/misc.h \
		${WRKSRC}/src/exp-gfx.c
	@${REINPLACE_CMD} -e 's|, ts|, \&ts|' ${WRKSRC}/test/date.c
	@${REINPLACE_CMD} -e 's|zvbi-atsc-cc$$(EXEEXT)||g; \
		s|zvbi-atsc-cc\.1||g' ${WRKSRC}/contrib/Makefile.in

.include <bsd.port.mk>
