# ex:ts=8
# Ports collection makefile for:	qtutils
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qtutils
PORTVERSION=	0.0.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.flyn.org/projects/qtutils/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	QuickTime Utilities

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		quicktime:${PORTSDIR}/graphics/libquicktime \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	qtconv.1 qtsg.1 qtsplit.1

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" \
		-e "s,-lglib,-lglib12,g" -e "s,-ldl,,g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
