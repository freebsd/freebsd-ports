# New ports collection makefile for:	id3lib
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	id3lib
PORTVERSION=	3.7.13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

INSTALLS_SHLIB=	yes
USE_NEWGCC=	yes
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-extract:
.for i in zlib popt
	${RM} -rf ${WRKSRC}/$i
.endfor

.include <bsd.port.mk>
