# New ports collection makefile for:	ode
# Date created:				11 Oct 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	ode
PORTVERSION=	0.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	opende
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Articulated rigid body dynamics library

CONFLICTS=	ode-devel-[0-9].*

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes

OPTIONS=	OPCODE "Enable code required by TriList (trimesh) class" on

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|g' \
		${WRKSRC}/configurator.c

	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; \
		s|-Wall||g; \
		s|-L/usr/X11/lib|-lXext|; \
		s|-L/usr/lib/X11R6||; \
		s|-L/usr/lib/X11||; \
		s|-L/usr/X11R6/lib|-L${X11BASE}/lib|; \
		s|-fno-rtti||; \
		s|-ffast-math|${CXXFLAGS} -I${X11BASE}/include|' \
		${WRKSRC}/config/makefile.unix-gcc
.if !defined(WITHOUT_OPCODE)
	@${REINPLACE_CMD} -e \
		's/^#OPCODE_DIRECTORY/OPCODE_DIRECTORY/' \
		${WRKSRC}/config/user-settings
.endif

do-configure:
	cd ${WRKSRC} ; ${GMAKE} configure
	@${REINPLACE_CMD} -e '/include.*values.h/d' ${WRKSRC}/include/ode/config.h

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/libode.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/libdrawstuff.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/ode
	@${INSTALL_DATA} ${WRKSRC}/include/ode/*.h ${PREFIX}/include/ode

.include <bsd.port.post.mk>
