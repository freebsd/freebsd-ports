# New ports collection makefile for:	doodle
# Date created:				26 June 2005
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	doodle
PORTVERSION=	0.6.7
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://gnunet.org/doodle/download/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Quickly search documents

LIB_DEPENDS=	extractor.3:${PORTSDIR}/textproc/libextractor

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		doodle.1 doodled.1
MAN3=		libdoodle.3

post-patch:
	@${REINPLACE_CMD} -e \
		's|,\$$PTHREAD_CPPFLAGS,|,${PTHREAD_CFLAGS},|; \
		 s|,\$$PTHREAD_LIBS,|,${PTHREAD_LIBS},|; \
		 s|,\$$PTHREAD_LDFLAGS,|,,|;' ${WRKSRC}/configure

.include <bsd.port.mk>
