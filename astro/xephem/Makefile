# New ports collection makefile for:    xephem
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xephem
PORTVERSION=	3.7.4
CATEGORIES=	astro
MASTER_SITES=	# http://www.clearskyinstitute.com/xephem/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	An interactive astronomical ephemeris program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg

USE_MOTIF=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem

MAN1=		xephem.1

RESTRICTED=	Personal use only

# XXX needs to be the same as DISTFILES
XEPHEMSRC=	${PORTNAME}-${PORTVERSION}.tar.gz

.include <bsd.port.pre.mk>

.for file in ${XEPHEMSRC}
.if !exists(${DISTDIR}/${file}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=	${PRINTF}
IGNORE=:\n\
Because of licensing restrictions, you must manually fetch\n\
${file} from http://www.clearskyinstitute.com/xephem/,\n\
place it in ${DISTDIR} and then run make again.\n
.endif
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${X11BASE}|g' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKSRC}/../.. -name Makefile -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's|CC =|CC?=|g ; \
		s|CFLAGS=|CFLAGS+=|g ; \
		s|-O2 ||g'

pre-build:
	@${ECHO_CMD} 'XEphem.ShareDir: ${PREFIX}/lib/X11/xephem' > ${WRKSRC}/XEphem.ad

pre-install:
	@${FIND} ${WRKSRC}/../.. -name Makefile.bak -type f | ${XARGS} ${RM} -f
	@${CP} ${WRKSRC}/xephem.man ${WRKSRC}/xephem.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xephem.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad ${PREFIX}/lib/X11/app-defaults/XEphem
	@${MKDIR} ${PREFIX}/lib/X11/xephem
	${TAR} -C ${WRKSRC} -cf - auxil catalogs fifos fits gallery help lo tools \
		| ${TAR} -C ${PREFIX}/lib/X11/xephem --unlink -xf -
	@${FIND} ${PREFIX}/lib/X11/xephem | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGROUP}
	@${FIND} ${PREFIX}/lib/X11/xephem -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.post.mk>
