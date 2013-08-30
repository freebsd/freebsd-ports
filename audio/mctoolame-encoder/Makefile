# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mctoolame
PORTVERSION=	0.1.a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-01a
PKGNAMESUFFIX=	-encoder
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG Layer II audio encoder with multi-channel support

USES=		gmake
ALL_TARGET=	#
MAKE_ARGS=	CC="${CC}" OPTIM="${CFLAGS}"
PLIST_SUB=	PKGNAMESUFFIX="${PKGNAMESUFFIX}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(ARCH)||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		's|gets *\(([^,)]+)\)|fgets(\1, sizeof(\1), stdin)|' \
			${WRKSRC}/config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mctoolame ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}${PKGNAMESUFFIX}/html
.endif

.include <bsd.port.mk>
