# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	0.3.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		intl.1:${PORTSDIR}/devel/gettext \
		glade.4:${PORTSDIR}/devel/libglade

USE_GLIB=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_GMAKE=	yes
MAKE_ARGS=	LDFLAGS="${CFLAGS} -L${LOCALBASE}/lib -lgnugetopt"

.include <bsd.port.mk>
