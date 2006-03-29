# New ports collection makefile for:  kicad
# Date created:               29 November 2005
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		kicad
DISTVERSION=		2006-03-28
CATEGORIES=		cad
MASTER_SITES=		ftp://iut-tice.ujf-grenoble.fr/cao/:dat		\
			ftp://ftp.lis.inpg.fr/uploads/kicad/:dat	\
			http://iut-tice.ujf-grenoble.fr/cao/:dat	\
			ftp://iut-tice.ujf-grenoble.fr/cao/sources/:src	\
			ftp://ftp.lis.inpg.fr/uploads/kicad/sources/:src\
			http://iut-tice.ujf-grenoble.fr/cao/sources/:src
DISTFILES=		${PORTNAME}-${DISTVERSION}.tgz:dat		\
			${PORTNAME}-sources-${DISTVERSION}${EXTRACT_SUFX}:src
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${PORTNAME}-sources-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Schematic and PCB editing software

LIB_DEPENDS=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26

.if !defined(NOPORTDOCS)
DISTFILES+=	doc_components-${DOCVERSION}${EXTRACT_SUFX}:dat
DOCVERSION=	2006-03-07
. if defined(PACKAGE_BUILDING)	# unzip is used during post-install:
RUN_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
. endif
.endif

WRKSRC=		${WRKDIR}/kicad-dev
MAKEFILE=	makefile.gtk

USE_ZIP=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GL=		yes

MAKE_ENV=	WX_CONFIG=${WX_CONFIG}

WX_CONFIG=	wxgtk2-2.6-config

INSTDIR=	${PORTNAME}
PLIST_SUB=	INSTDIR=${INSTDIR} OPSYS=${OPSYS}

BINS=		cvpcb eeschema gerbview kicad pcbnew

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/konqueror)
RUN_DEPENDS+=	konqueror:${PORTSDIR}/x11/kdebase3
.else
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
.endif

.if ${OSVERSION} < 500000
BROKEN=	Does not compile on ${OSVERSION}
.endif

post-extract:
	for f in `${FIND} ${WRKSRC} -name ${MAKEFILE}`; do		\
		${CP} $$f $$f.dos &&					\
		${TR} -d '\r' < $$f.dos > $$f ;				\
	done
	${CP} ${WRKSRC}/libs.linux ${WRKSRC}/libs.${OPSYS}
	${REINPLACE_CMD} -e 's|kicad/linux|${INSTDIR}/${OPSYS}|'	\
		${WRKSRC}/libs.${OPSYS}

pre-configure:
	for f in `${FIND} ${WRKSRC} -name ${MAKEFILE}`; do		\
		${REINPLACE_CMD} -e 's|CC = gcc|#CC = gcc|'		\
			-e 's|LD = gcc|LD = ${CC}|'			\
			-e 's|-O2|${CFLAGS} -I${X11BASE}/include|'	\
			-e 's|wx-config|${WX_CONFIG}|'			\
			-e 's|LDFLAGS =|LDFLAGS += -L${X11BASE}/lib|'	\
			-e 's|libs.linux|libs.${OPSYS}|'		\
			-e 's|gcc -D|${CC} -D|' $$f ;			\
	done
	${REINPLACE_CMD} -e 's|kicad/linux|${INSTDIR}/${OPSYS}|'	\
		-e 's|/usr/local|${PREFIX}|' ${WRKSRC}/common/gestfich.cpp
	${REINPLACE_CMD} -e 's|/usr/bin/xpdf|${X11BASE}/bin/xpdf|'	\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		${WRKSRC}/common/eda_doc.cpp

pre-install:
	${MKDIR} ${PREFIX}/${INSTDIR}/${OPSYS}/plugins
	(cd ${PREFIX} && ${TAR} -xzopf ${_DISTDIR}/${PORTNAME}-${DISTVERSION}.tgz)
	${RM} -rf ${PREFIX}/${INSTDIR}/linux-non_unicode		\
		${PREFIX}/${INSTDIR}/linux ${PREFIX}/${INSTDIR}/wings3d	\
		${PREFIX}/${INSTDIR}/LINUX.README
	${RMDIR} ${PREFIX}/${INSTDIR}/modules/packages3d/conn_HExx

post-install:
	${LN} -sf ${BINS:S|^|${PREFIX}/${INSTDIR}/${OPSYS}/|} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${UNZIP_CMD} -oq ${_DISTDIR}/doc_components-${DOCVERSION}${EXTRACT_SUFX} \
		-d ${PREFIX}/${INSTDIR}/library
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${INSTDIR}/library/doc
.else
	${RM} -rf ${PREFIX}/${INSTDIR}/library/doc
.endif
	${RMDIR} ${PREFIX}/${INSTDIR}/internat/pl	# Prune empty dir
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
