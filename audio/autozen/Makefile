# New ports collection makefile for:	autozen
# Date created:				2000-09-16
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	autozen
PORTVERSION=	1.3.1
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxlabs.com/software/download/
DISTNAME=	AutoZen-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

WRKSRC=		${WRKDIR}/AutoZen-${PORTVERSION}

MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

USE_X_PREFIX=	yes
USE_GTK=	yes

DOC_FILES=	CHANGES COPYING
DATA_FILES=	deep-relax.seq deep_delta_slide.seq delta_slide.seq \
		moderate-meditation.seq relax.seq wake-up.seq
PLIST=		${WRKDIR}/pkg-plist

post-patch:
	@if [ -f /usr/include/sys/soundcard.h ]; then \
		${PERL} -pi -e "s=machine/soundcard.h=sys/soundcard.h=g" \
			${WRKSRC}/autozen.c; \
	fi
	@${PERL} -pi -e "s=X11BASE=${X11BASE}=g" ${WRKSRC}/autozen.c
	cd ${WRKSRC} && ${RM} autozen seq2wav

pre-install:
	${ECHO} bin/autozen > ${PLIST}
	${ECHO} bin/seq2wav >> ${PLIST}
.for i in ${DATA_FILES}
	${ECHO} share/autozen/${i} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for i in ${DOC_FILES}
	${ECHO} share/doc/autozen/${i} >> ${PLIST}
.endfor
	${ECHO} @dirrm share/doc/autozen >> ${PLIST}
.endif
	${ECHO} @dirrm share/autozen >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autozen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/seq2wav ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/autozen
.for i in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/autozen
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/autozen
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/autozen
.endfor
.endif

.include <bsd.port.mk>
