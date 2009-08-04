# New ports collection makefile for:    cmake
# Date created:         March 18 2002
# Whom:                 Kyle Martin <mkm@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	cmake
PORTVERSION=	2.6.4
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v${PORTVERSION:C/\.[[:digit:]]+$//}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A cross-platform make

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${DATADIR:S|^${PREFIX}||} \
		--docdir=${DOCSDIR:S|^${PREFIX}||}
CONFIGURE_ENV=	MAKE=make

MAKE_JOBS_SAFE=	yes

.if !defined(WITH_DEBUG)
INSTALL_TARGET=install/strip
.endif

MAN1=		ccmake.1 \
		cmake.1 \
		cmakecommands.1 \
		cmakecompat.1 \
		cmakemodules.1 \
		cmakepolicies.1	\
		cmakeprops.1 \
		cmakevars.1 \
		cpack.1 \
		ctest.1

post-patch:
	@${GREP} -rl '/usr/X11R6' ${WRKSRC}/Modules ${WRKSRC}/Tests | \
		${XARGS} ${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'
	@${REINPLACE_CMD} -e 's,/opt/kde4,${LOCALBASE}/kde4,g' \
		${WRKSRC}/Modules/FindKDE4.cmake

.include <bsd.port.mk>
