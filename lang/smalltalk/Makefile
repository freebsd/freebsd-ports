# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	1.95.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all optimize

MAN1=		gst.1

PLIST_SUB=	VERSION=${PORTVERSION}

post-extract:
	@${RM} ${WRKSRC}/doc/gst.info*

pre-patch:
	@${PERL} -pi -e 's|-lregex|-lgnuregex|g ; \
		 s|\$$\OPT_CFLAGS||g' ${WRKSRC}/configure

	@find ${WRKSRC} -name 'Makefile.in' | xargs ${PERL} -pi -e \
		's|make mostlyclean|\$$\(MAKE\) mostlyclean|g ; \
		 s|\@MAKEINFO\@|\@MAKEINFO\@ --no-split|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/libgst/.libs/libgst.a ${PREFIX}/lib

.include <bsd.port.mk>
