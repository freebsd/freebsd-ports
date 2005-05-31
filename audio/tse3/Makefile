# New ports collection makefile for:    tse3
# Date created:				Wed Nov 12 14:10:12 PST 2003
# Whom:					Mathew Kanner <mat@hak.cnd.mcgill.ca>
#
# $FreeBSD$

PORTNAME=	tse3
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A MIDI library

LIB_DEPENDS=	artsc:${PORTSDIR}/audio/arts

USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

MAN1=	tse3play.1
MAN3=	tse3.3

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
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

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e 's|prefix}/doc/$${PACKAGE}-$${VERSION}|prefix}/share/doc/$${PACKAGE}|'

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -x -n 10 \
	${REINPLACE_CMD} -e 's|_LDFLAGS =|_LDFLAGS = ${PTHREAD_LIBS}|g'

.include <bsd.port.post.mk>
