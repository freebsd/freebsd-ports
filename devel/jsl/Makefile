# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	jsl
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.Awfulhak.org/pub/jsl/ \
		http://www.javascriptlint.com/download/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Analyzes JavaScript code looking for bugs and signs of poor quality

PLIST_FILES=	bin/jsl
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USES=		gmake
MAKEFILE=	Makefile.ref
MAKE_ARGS=	OS_CFLAGS="-DXP_UNIX -DHAVE_VA_COPY -DVA_COPY=va_copy"
CFLAGS+=	-fPIC
MAKE_JOBS_UNSAFE=	yes
LLD_UNSAFE=	yes

.include <bsd.port.pre.mk>

JSLCFG_CMD=	${UNAME} -sr | ${SED} 's, ,,'

post-patch:
	${GREP} -v 'CC =' ${WRKSRC}/config/Linux_All.mk > ${WRKSRC}/config/$$(${JSLCFG_CMD}).mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/$$(${JSLCFG_CMD})_DBG.OBJ/jsl ${STAGEDIR}${PREFIX}/bin/jsl

.include <bsd.port.post.mk>
