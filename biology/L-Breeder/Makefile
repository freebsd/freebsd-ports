# New ports collection makefile for:	L-Breeder
# Date created:				30 May 2002
# Whom:					David Yeske <dyeske@yahoo.com> et al
#
# $FreeBSD$
#

PORTNAME=	L-Breeder
PORTVERSION=	1.0
CATEGORIES=	biology
MASTER_SITES=	http://pixie.oum.ox.ac.uk/L-Breeder/
DISTNAME=	LBreeder
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com

LIB_DEPENDS=	wx_gtk-2.2_gl.2:${PORTSDIR}/x11-toolkits/wxgtk

BROKEN=		Unknown problem

WRKSRC=		${WRKDIR}/LBreeder/LBreeder
PATCH_WRKSRC=	${WRKDIR}/LBreeder

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_MESA=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} ">>>"
	@${ECHO_MSG} ">>> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS."
	@${ECHO_MSG} ">>> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
	@${ECHO_MSG} ">>>"
.endif

post-patch:
# uphold C{C,XX}
	@${FIND} ${WRKDIR} -type f -name Makefile | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|g\+\+|${CXX}|;s|gcc|${CC}|'
# both uphold CFLAGS and protect ARCHs where greater than -O is not
# safe
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2|"${CFLAGS}"|' ${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -e 's|-O2|"${CFLAGS} -O2"|' ${WRKSRC}/Makefile
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/L-Breeder ${PREFIX}/bin

.include <bsd.port.mk>
