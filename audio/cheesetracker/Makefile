# ex:ts=8
# Ports collection makefile for:	cheesetracker
# Date created:			Jan 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cheesetracker
PORTVERSION=	0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://www.reduz.com.ar/cheesetracker/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/automake14/install-sh:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-patch:
	@${REINPLACE_CMD} -e 's|[$$]CXXFLAGS_OPT |\$$CXXFLAGS |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|AFMT_S16_NE|AFMT_S16_LE|g' ${WRKSRC}/waveout/sound_driver_oss.cpp

pre-configure:
.for file in install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/${file} ${WRKSRC}
.endfor
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
