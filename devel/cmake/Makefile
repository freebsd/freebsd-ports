# New ports collection makefile for:    cmake
# Date created:         March 18 2002
# Whom:                 Kyle Martin <mkm@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	cmake
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v${PORTVERSION:C/\.[[:digit:]]+$//}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A cross-platform make

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${DATADIR:S|^${PREFIX}||} \
		--docdir=${DOCSDIR:S|^${PREFIX}||}
CONFIGURE_ENV=	MAKE=make

MAN1=		ccmake.1 \
		cmake.1 \
		cmakecommands.1 \
		cmakecompat.1 \
		cmakemodules.1 \
		cmakeprops.1 \
		cmakevars.1 \
		cpack.1 \
		ctest.1

post-patch:
	@${GREP} -rl '/usr/X11R6' ${WRKSRC}/Modules ${WRKSRC}/Tests | \
		${XARGS} ${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'

.include <bsd.port.mk>
