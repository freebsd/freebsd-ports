# ex:ts=8
# Ports collection makefile for:	autools
# Date created:			Jul 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	autools
PORTVERSION=	1.2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.tnt.uni-hannover.de/~purnhage/software/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of programs to manipulate audio files

BUILD_DEPENDS=	${LOCALBASE}/lib/libtsp.a:${PORTSDIR}/audio/afsp

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	AFSP_INCLUDE_PATH="${LOCALBASE}/include" \
		AFSP_LIBRARY_PATH="${LOCALBASE}/lib"

PROGRAMS=	ac3spdif augen auquant auquery fifo plax playlist randhead \
		wav2au
SCRIPTS=	catcol dao2toc genam genfm toc2plax-cut toc2plax-idx \
		toc2plax-trk toc2toc wav2toc

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS = -O3|CFLAGS +=|g' ${WRKSRC}/Makefile

do-install:
.for file in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/unknown/${file} ${PREFIX}/bin
.endfor
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
