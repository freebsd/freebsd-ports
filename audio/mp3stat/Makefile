# ex:ts=8
# Ports collection makefile for:	mp3stat
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3stat
PORTVERSION=	2.5.2
CATEGORIES=	audio
MASTER_SITES=	http://safemode.homeip.net/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_GTK=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CFLAGS+=	-I${LOCALBASE}/include
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,glib-config,${GLIB_CONFIG},g ; \
		s,gtk-config,${GTK_CONFIG},g ; \
		s,^CXXFLAGS *=,CXXFLAGS+=,g" ${WRKSRC}/Makefile
# current vorbis support is broken, dont know how to fix
	@${PERL} -pi -e "s,^VORBIS,#VORBIS,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
