# New ports collection makefile for:	linpsk
# Date created:				29 May 2005
# Whom:					Søren Straarup <xride@x12.dk>
#
# $FreeBSD$
#

PORTNAME=	linpsk
PORTVERSION=	0.8.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	xride@x12.dk
COMMENT=	A qt psk31 client

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		portaudio:${PORTSDIR}/audio/portaudio

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-qtdir=${X11BASE}

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-I$$(top_srcdir)/src/portaudio||' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/interfaces/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(top_builddir)/src/portaudio/libportaudio\.a|-lportaudio|; \
		 /^SUBDIRS =/ s|portaudio||' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O2|${CXXFLAGS}|; \
		 /^install-exec-am/ s|install-libLIBRARIES||' \
		${WRKSRC}/src/interfaces/Makefile.in

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/LinPSKConfig.xml ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
