# ex:ts=8
# Ports collection makefile for:	gnump3d
# Date created:			May 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnump3d
PORTVERSION=	0.9.9.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=	gnump3d.1 gnump3d.conf.1 gnump3d-config.1 gnump3d-top.1

.if !defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis
.endif

pre-everything::
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile without Ogg/Vorbis support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITHOUT_VORBIS=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|=aclocal|=${TRUE}|g ; \
		 s|=autoconf|=${TRUE}|g ; \
		 s|=automake|=${TRUE}|g ; \
		 s|=autoheader|=${TRUE}|g ; \
		 s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|#undef socklen_t||g' ${WRKSRC}/src/config.h.in

.include <bsd.port.mk>
