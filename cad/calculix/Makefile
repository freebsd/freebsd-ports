# New ports collection makefile for:	CalculiX
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	CalculiX
PORTVERSION=	1.0
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	ccx_${PORTVERSION}.src.tar.gz cgx_${PORTVERSION}.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	ccx_${PORTVERSION}.ps.tar.gz cgx_${PORTVERSION}.ps.tar.gz
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Three-Dimensional Structural Finite Element Program

# These are required to build Crunchix (ccx)
BUILD_DEPENDS=	${LOCALBASE}/lib/libspooles.a:${PORTSDIR}/math/spooles \
		${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/arpack

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_MESA=	yes
USE_REINPLACE= yes

.if !defined(WITH_EXAMPLES)
PLIST_SUB=      WITH_EXAMPLES="@comment "
.else
PLIST_SUB=      WITH_EXAMPLES=""
.endif

.ifndef (WITH_EXAMPLES)
pre-everything::
	@${ECHO} "You can define WITH_EXAMPLES=yes to install example files"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g;' ${WRKSRC}/ccx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g;' ${WRKSRC}/ccx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/ccx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%X11BASE%%+${X11BASE}+g;' ${WRKSRC}/cgx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%CFLAGS%%+${CFLAGS}+g;'   ${WRKSRC}/cgx_${PORTVERSION}/src/Makefile
do-build:
	@(cd ${WRKSRC}/ccx_${PORTVERSION}/src; $(MAKE) )
	@(cd ${WRKSRC}/cgx_${PORTVERSION}/src; $(MAKE) )
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ccx_${PORTVERSION}/src/ccx_${PORTVERSION} \
	  ${PREFIX}/bin/ccx
	@${INSTALL_PROGRAM} ${WRKSRC}/cgx_${PORTVERSION}/src/cgx \
	  ${PREFIX}/bin/cgx
.ifdef (WITH_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} cf - -C ${WRKSRC}/cgx_${PORTVERSION}/examples . | ${TAR} xf - -C ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/CalculiX
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/*.ps \
	  ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cgx_${PORTVERSION}/doc/*.ps \
	  ${DOCSDIR}
.endif

.include <bsd.port.mk>
