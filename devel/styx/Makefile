# ex:ts=8
# New ports collection makefile for:	styx
# Date created:			Apr 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	styx
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.speculate.de/styx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${PREFIX}/include" \
		LIBS="-L${PREFIX}/lib -lgiconv"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/styx \
		--datadir=${PREFIX}/share/doc/styx

USE_GMAKE=	yes

post-patch:
.for file in config.h.in configure libbase/styconf0.h
	@${PERL} -pi -e "s,iconv.h,giconv.h,g" ${WRKSRC}/${file}
.endfor
.for file in config.h.in libbase/styconf0.h libbase/gstream.c
	@${PERL} -pi -e "s,ICONV_H,GICONV_H,g" ${WRKSRC}/${file}
.endfor

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
