# New ports collection makefile for:	han
# Date created:		12 Apr 1997
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	han
PORTVERSION=	1.0fb
PORTREVISION=	1
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	A hangul console

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	YES
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/vt.c ${WRKSRC}/lib/mem.c

post-configure:
	${SED} -e 's%%WRKSRC%%${WRKSRC}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  ${FILESDIR}/dotconfig > ${WRKSRC}/.config
	${SED} -e 's%%WRKSRC%%${WRKSRC}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  ${FILESDIR}/han.sh > ${WRKSRC}/han.sh

.include <bsd.port.post.mk>
