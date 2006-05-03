# New ports collection makefile for:	liblzxcomp
# Date created:	   27 Feb 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	liblzxcomp
PORTVERSION=	20020619
CATEGORIES=	archivers
MASTER_SITES=	http://www.speakeasy.org/~russotto/chm/
DISTNAME=	lzx_compress

MAINTAINER=	skv@FreeBSD.org
COMMENT=	LZX compression library

MAKE_ENV=	PREFIX=${PREFIX}

INSTALLS_SHLIB=	YES
SHLIB_MAJOR=	1
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

MAN3=		lzxcomp.3
MANCOMPRESSED=	yes

.if defined(NOPROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	@${SED} -e "s=%%SHLIB_MAJOR%%=${SHLIB_MAJOR}=g" \
		${FILESDIR}/Makefile > ${WRKSRC}/Makefile
	${REINPLACE_CMD} -i '' -e 's|stdint|sys/types|' \
		${WRKSRC}/lzx_compress.mdoc3 ${WRKSRC}/lzx_layer.c
	${MV} ${WRKSRC}/lzx_compress.mdoc3 ${WRKSRC}/lzxcomp.3

.include <bsd.port.mk>
