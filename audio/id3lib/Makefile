# New ports collection makefile for:	id3lib
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	id3lib
PORTVERSION=	3.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=		"Doesn't link properly, std::char_traits<wchar_t> thingie"
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/zlib

post-install:
	@${RM} -f ${LOCALBASE}/lib/libid3.la

.include <bsd.port.post.mk>
