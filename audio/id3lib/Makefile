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
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib" CPPFLAGS="-I${PREFIX}/include"

post-extract:
.for i in zlib popt
	${RM} -rf ${WRKSRC}/$i
.endfor

.include <bsd.port.mk>
