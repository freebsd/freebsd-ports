# ex:ts=8
# Ports collection makefile for:	autools
# Date created:			Jul 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	autools
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	http://www.tnt.uni-hannover.de/~purnhage/software/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of programs to manipulate audio files

BUILD_DEPENDS=	${LOCALBASE}/lib/libtsp.a:${PORTSDIR}/audio/afsp

USE_GMAKE=	yes
MAKE_ENV=	AFSP_INCLUDE_PATH="${LOCALBASE}/include" \
		AFSP_LIBRARY_PATH="${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS = -O3|CFLAGS +=|g ; \
		s|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
