# ex:ts=8
# Ports collection makefile for:  ddd
# Version required:     	  3.1.3
# Date created:			  Tue Jan 28, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	ddd-3.1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ips.cs.tu-bs.de/pub/local/softech/ddd/src/  \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/ddd/src/  \
		ftp://ftp.gre.ac.uk/pub/tools/debuggers/ddd/src/  \
		ftp://richb-pc.acc.qc.edu/pub/ddd/src/  \
		ftp://ftp.th-darmstadt.de/pub/programming/tools/ddd/src/

MAINTAINER=     obrien@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-motif-libraries="${LIBXMDIR}"
USE_GMAKE=	yes
REQUIRES_MOTIF=	yes
MAN1=		ddd.1

.if defined(MOTIFLIB)
.if defined(MOTIF_STATIC)
LIBXMDIR!=	${ECHO} ${MOTIFLIB} | sed -e 's/\/libXm\.a//g' | awk '{print $$1}'
.else
LIBXMDIR!=	${ECHO} ${MOTIFLIB} | sed -e 's/-L//g' | awk '{print $$1}'
.endif
.else
LIBXMDIR=	${X11BASE}
.endif

post-configure:
	${ECHO} "LIBXM = ${MOTIFLIB}" >> ${WRKSRC}/ddd/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/PROBLEMS ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd-paper.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.man.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/sample.dddinit ${PREFIX}/share/doc/ddd
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd.man.ps
.endif

check:
	(cd ${WRKSRC} ; ${GMAKE} check)

.include <bsd.port.mk>
