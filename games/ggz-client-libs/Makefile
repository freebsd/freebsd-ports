# ex:ts=8
# Ports collection makefile for:	ggz-client-libs
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-client-libs
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Core Client Libraries

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		expat.4:${PORTSDIR}/textproc/expat2 \
		ggz.1:${PORTSDIR}/games/libggz

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-debug

INSTALLS_SHLIB=	yes

MAN3=	ggzcore_h.3 ggzmod_h.3
MAN5=	ggz.modules.5
MAN6=	ggz-config.6

.include <bsd.port.mk>
