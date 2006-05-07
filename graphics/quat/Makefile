# New ports collection makefile for:	quat
# Date created:				26 Aug 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	quat
PORTVERSION=	1.20
CATEGORIES=	graphics
MASTER_SITES=   http://www.physcip.uni-stuttgart.de/phy11733/download/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A Three-dimensional fractal creator (command line only)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gui \
		--datadir=${PREFIX}/share/doc

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's,-(march=pentium|O3|ffast-math),,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-I\.[[:space:]]+-I\$$\(srcdir\)[[:space:]]+||' \
		${WRKSRC}/kernel/Makefile.in
# disable data file installation since distfile does not do
# The Right Thing(TM)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am:).*$$|\1|' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e \
		's|^(SUBDIRS.*)doc|\1|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
