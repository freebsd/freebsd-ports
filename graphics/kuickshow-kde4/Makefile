# New ports collection makefile for:	kuickshow
# Date created:		5 May 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	kuickshow
PORTVERSION=	0.8.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

USE_REINPLACE=	yes
USE_IMLIB=	yes
USE_KDELIBS_VER=	2
USE_GMAKE=	yes

CONFIGURE_ENV+=	KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-imlib-config=${X11BASE}/bin

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	@(cd ${WRKSRC}/doc && ${GMAKE} real-install)
.endif

.include <bsd.port.mk>
