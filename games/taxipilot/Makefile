# New ports collection makefile for:	taxipilot
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	taxipilot
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	taxipilot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spacetaxi clone

LIB_DEPENDS=	noatun.0:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g ; \
		 s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/aclocal.m4

pre-configure:
	@cd ${WRKSRC} && ${AUTOHEADER}

.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
