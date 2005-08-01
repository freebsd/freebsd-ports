# New ports collection makefile for:    tse3
# Date created:				Wed Nov 12 14:10:12 PST 2003
# Whom:					Mathew Kanner <mat@hak.cnd.mcgill.ca>
#
# $FreeBSD$

PORTNAME=	tse3
PORTVERSION=	0.3.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A MIDI library

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-doc-install
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

MAN1=		tse3play.1
MAN3=		tse3.3

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsmidi:${PORTSDIR}/multimedia/kdemultimedia3
.else
CONFIGURE_ARGS+=	--without-aRts
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} -n "checking for SNDCTL_SEQ_GETTIME in sys/soundcard.h... "
	@if ${GREP} -q SNDCTL_SEQ_GETTIME /usr/include/sys/soundcard.h; then\
	${ECHO_MSG} "yes";\
	${ECHO_MSG};\
	else\
	${ECHO_MSG} "no";\
	${ECHO_MSG};\
	${ECHO_MSG} "********************************************************************************";\
	${ECHO_MSG} "* This port requires:                                                          *";\
	${ECHO_MSG} "*                                                                              *";\
	${ECHO_MSG} "* FreeBSD-CURRENT newer than Nov 22 03:27:09 2003 UTC (or FreeBSD 5.3-Release) *";\
	${ECHO_MSG} "*                                                                              *";\
	${ECHO_MSG} "*                                      OR                                      *";\
	${ECHO_MSG} "*                                                                              *";\
	${ECHO_MSG} "* FreeBSD-STABLE newer than Jul 20 13:49:30 2004 UTC (or FreeBSD 4.11-Release) *";\
	${ECHO_MSG} "********************************************************************************";\
	${ECHO_MSG};\
	${ECHO_MSG} "Aborting."; exit 1;\
	fi

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpeg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/History ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/songs
	${INSTALL_DATA} ${WRKSRC}/demos/*.tse3 ${DOCSDIR}/songs
.endif

.include <bsd.port.post.mk>
