# ex:ts=8
# Ports collection makefile for:  ddd
# Date created:			  Tue Jan 28, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ddd
PORTVERSION=	3.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= ddd

MAINTAINER=	lioux@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-motif-libraries="${LIBXMDIR}" \
		--with-readline-libraries=/usr/lib
USE_GMAKE=	yes
USE_XPM=	yes
USE_MOTIF=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

MAN1=		ddd.1

CFLAGS+= -Wno-deprecated

.if defined(MOTIFLIB)
.if defined(MOTIF_STATIC)
LIBXMDIR!=	${ECHO_CMD} ${MOTIFLIB} | ${SED} -e 's/\/libXm\.a//g' | ${AWK} '{print $$1}'
.else
LIBXMDIR!=	${ECHO_CMD} ${MOTIFLIB} | ${SED} -e 's/-L//g' | ${AWK} '{print $$1}'
.endif
.else
LIBXMDIR=	${X11BASE}
.endif

pre-patch:
	${RM} -fv ${WRKSRC}/ddd/ddd.info*
	${RM} -fv ${WRKSRC}/ddd/ddd-themes.info*

pre-configure:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} \
		${PERL} -pi -e "s|-O2|-g|"

post-configure:
	${ECHO_CMD} "LIBXM = ${MOTIFLIB}" >> ${WRKSRC}/ddd/Makefile

post-install:
	@${RM} ${PREFIX}/lib/libiberty.a
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/PROBLEMS ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd-paper.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/sample.dddinit ${PREFIX}/share/doc/ddd
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd.ps
.endif

check:
	(cd ${WRKSRC} ; ${GMAKE} check)

.include <bsd.port.mk>
