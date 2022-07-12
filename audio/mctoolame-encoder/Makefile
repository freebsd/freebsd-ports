# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>

PORTNAME=	mctoolame
PORTVERSION=	0.1.a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-01a
PKGNAMESUFFIX=	-encoder
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG Layer II audio encoder with multi-channel support

DEPRECATED=	Legacy and obscure audio format that never gained any traction
EXPIRATION_DATE=2022-09-30

USES=		gmake tar:tgz
ALL_TARGET=	#
MAKE_ARGS=	CC="${CC}" OPTIM="${CFLAGS}"
PLIST_SUB=	PKGNAMESUFFIX="${PKGNAMESUFFIX}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|$$(ARCH)||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		's|gets *\(([^,)]+)\)|fgets(\1, sizeof(\1), stdin)|' \
			${WRKSRC}/config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mctoolame ${STAGEDIR}${PREFIX}/bin
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}${PKGNAMESUFFIX}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}${PKGNAMESUFFIX}/html

.include <bsd.port.mk>
