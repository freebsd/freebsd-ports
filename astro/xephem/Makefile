# New ports collection makefile for:    xephem
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xephem
PORTVERSION=	3.6
CATEGORIES=	astro
MASTER_SITES=	# http://www.clearskyinstitute.com/xephem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive astronomical ephemeris program

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_REINPLACE=	yes
MAN1=		xephem.1

LIBASTROSRC=	${WRKDIR}/${DISTNAME}/libastro
LIBIPSRC=	${WRKDIR}/${DISTNAME}/libip
LIBJPEGDSRC=	${WRKDIR}/${DISTNAME}/libjpegd
LIBLILXMLSRC=	${WRKDIR}/${DISTNAME}/liblilxml

NO_CDROM=	Personal use only

# XXX needs to be the same as DISTFILES
XEPHEMSRC=	${PORTNAME}-${PORTVERSION}.tar.gz

.include <bsd.port.pre.mk>

.for file in ${XEPHEMSRC}
.if !exists(${DISTDIR}/${file})
ECHO_MSG=	/usr/bin/printf
IGNORE=:\n\
Because of licensing restrictions, you must manually fetch\n\
${file} from http://www.clearskyinstitute.com/xephem/,\n\
place it in ${DISTDIR} and then run make again.\n
.endif
.endfor

post-patch:
	@${CHMOD} u+w ${LIBASTROSRC}/Makefile ${LIBIPSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CC =|CC?=|g ; \
		 s|CFLAGS=|CFLAGS+=|g ; \
		 s|-O2 ||g' ${LIBASTROSRC}/Makefile ${LIBIPSRC}/Makefile

pre-build:
	@cd ${LIBASTROSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}
	@cd ${LIBIPSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}
	@cd ${LIBJPEGDSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}
	@cd ${LIBLILXMLSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}
	@${ECHO_CMD} 'XEphem.ShareDir: ${PREFIX}/lib/X11/xephem' > ${WRKSRC}/XEphem.ad

post-install:
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad ${PREFIX}/lib/X11/app-defaults/XEphem
	@${MKDIR} ${PREFIX}/lib/X11/xephem
	${TAR} -C ${WRKSRC} -cf - auxil catalogs fits fifos help tools \
		| ${TAR} -C ${PREFIX}/lib/X11/xephem --unlink -xf -
	@${FIND} ${PREFIX}/lib/X11/xephem | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREMODE}
	@${FIND} ${PREFIX}/lib/X11/xephem -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.post.mk>
