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
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

INFO=		clint

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
USE_GCC=	3.3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-pedantic||g ; \
		 s|-ldl||g'

.include <bsd.port.post.mk>
