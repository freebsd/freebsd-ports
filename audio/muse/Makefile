# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	muse
PORTVERSION=	0.7.1
CATEGORIES=	audio
MASTER_SITES=	http://freesoftware.fsf.org/download/muse/ \
		http://muse.dyne.org/releases/
DISTNAME=	MuSE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,-lgthread,-lgthread12,g" ${WRKSRC}/configure
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
