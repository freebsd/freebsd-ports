# ex:ts=8
# New ports collection makefile for:	clint
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clint
PORTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A static source code checker for C++

USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

INFO=		clint

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-pedantic||g ; \
		 s|-ldl||g'

.include <bsd.port.mk>
