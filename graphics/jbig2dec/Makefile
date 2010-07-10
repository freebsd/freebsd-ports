# New ports collection makefile for:	jbig2dec
# Date created:		2010-07-07
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	jbig2dec
PORTVERSION=	0.11
CATEGORIES=	graphics devel
MASTER_SITES=	http://ghostscript.com/~giles/jbig2/jbig2dec/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Decoder implementation of the JBIG2 image compression format

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	PNG "Enable png support" On

MAN1=		jbig2dec.1

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.options.mk>

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng=${LOCALBASE}
.endif

post-patch:
.if defined(WITH_PNG)
	@${REINPLACE_CMD} 's/png_check_sig/png_sig_cmp/g' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
