# New ports collection makefile for:	pd
# Date created:				2002-05-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pd
PORTVERSION=	0.35.23
CATEGORIES=	audio
MASTER_SITES=	http://www-crca.ucsd.edu/~msp/Software/
DISTNAME=	pd-0.35-test23.linux

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -ltk83 -ltcl83"
MAKEFILE=	makefile
MAN1=		pd.1 pdreceive.1 pdsend.1
PATCH_WRKSRC=	${WRKSRC}/..
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/pd-0.35-test23/src

pre-patch:
	${CP} ${WRKSRC}/s_linux.c ${WRKSRC}/s_freebsd.c

post-patch:
	${FIND} ${WRKDIR} -type f -name '*.c' -exec ${PERL} -pi -e \
		"s:malloc.h:stdlib.h:g" {} \;

pre-configure:
	${CHMOD} +x ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	${PERL} -pi -e \
"s:^INCLUDE = :INCLUDE = -I${LOCALBASE}/include/tk8.3 -I${LOCALBASE}/include/tcl8.3 -I${X11BASE}/include :g; s:^LIB =:LIB =${PTHREAD_LIBS}:g; s:^CFLAGS =:CFLAGS+=${PTHREAD_CFLAGS}:g" \
		${WRKSRC}/makefile

pre-install:
	${RM} -f ${PLIST}
.for ii in pd pd-gui pd-watchdog pd.tk pdreceive pdsend
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} include/m_pd.h >> ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in LICENSE README
	${ECHO_CMD} share/doc/pd/${ii}.txt >> ${PLIST}
.endfor
	cd ${WRKSRC}/../doc && ${FIND} -s . -type f | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:share/doc/pd/:' >> ${PLIST} \
		&& ${FIND} -d . -type d | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:@dirrm share/doc/pd/:' >> ${PLIST}
	cd ${WRKSRC}/../extra && ${FIND} -s . -type f -or -type l | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:share/pd/:' >> ${PLIST} \
		&& ${FIND} -d . -type d | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:@dirrm share/pd/:' >> ${PLIST}
.endif

do-install:
.for ii in pd pd-gui pd-watchdog pdreceive pdsend
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/../bin/pd.tk ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/m_pd.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/../${ii}.txt ${DOCSDIR}
.endfor
	cd ${WRKSRC}/../doc && pax -r -w * ${DOCSDIR}
.endif
.for ii in pd pdreceive pdsend
	${INSTALL_MAN} ${WRKSRC}/../man/${ii}.1 ${PREFIX}/man/man1/
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/../extra && pax -r -w * ${DATADIR}

.include <bsd.port.mk>
