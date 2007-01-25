# New ports collection makefile for:	doodle
# Date created:				26 June 2005
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	doodle
PORTVERSION=	0.6.6
CATEGORIES=	deskutils
MASTER_SITES=	http://gnunet.org/doodle/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quickly search documents

LIB_DEPENDS=	extractor.2:${PORTSDIR}/textproc/libextractor

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		doodle.1 doodled.1
MAN3=		libdoodle.3

post-patch:
	@${REINPLACE_CMD} -e \
		's|,\$$PTHREAD_CPPFLAGS,|,${PTHREAD_CFLAGS},|; \
		 s|,\$$PTHREAD_LIBS,|,${PTHREAD_LIBS},|; \
		 s|,\$$PTHREAD_LDFLAGS,|,,|;' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
