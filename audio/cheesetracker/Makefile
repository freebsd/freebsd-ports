# ex:ts=8
# Ports collection makefile for:	cheesetracker
# Date created:			Jan 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cheesetracker
PORTVERSION=	0.2.4
CATEGORIES=	audio
MASTER_SITES=	http://www.reduz.com.ar/cheesetracker/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	sigc:${PORTSDIR}/devel/libsigc++ \
		gtkmm:${PORTSDIR}/x11-toolkits/gtk--

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

pre-configure:
.for file in install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/automake/${file} ${WRKSRC}
.endfor

post-patch:
	@${PERL} -pi -e "s,AFMT_S16_NE,AFMT_S16_LE,g" ${WRKSRC}/waveout/sound_driver_oss.cpp

.include <bsd.port.mk>
