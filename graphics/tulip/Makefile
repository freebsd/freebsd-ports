# ex:ts=8
# Ports collection makefile for:	tulip
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tulip
PORTVERSION=	1.2.2
CATEGORIES=	graphics
MASTER_SITES=	http://dept-info.labri.fr/~auber/projects/tulip/x345/tulip-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system dedicated to the visualization of huge graphs

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_MESA=	yes
USE_QT_VER=	3
CFLAGS+=	-DHAVE_DECL_GETOPT
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt -lcompat"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-lqt|-lqt-mt|" ${WRKSRC}/configure
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e "s|-ldl||" -e "s|-lpthread|${PTHREAD_LIBS}|"

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} \
		-e "s|-D_GETOPT_H||"

pre-build:
	@(cd ${WRKSRC} && ${GMAKE} clean)

.include <bsd.port.mk>
