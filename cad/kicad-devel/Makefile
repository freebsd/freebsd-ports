# New ports collection makefile for:  kicad
# Date created:               29 November 2005
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		kicad
DISTVERSION=		2007-07-02
CATEGORIES=		cad
#MASTER_SITES=		ftp://iut-tice.ujf-grenoble.fr/cao/:dat		\
#			ftp://ftp.lis.inpg.fr/uploads/kicad/:dat	\
#			http://iut-tice.ujf-grenoble.fr/cao/:dat	\
#			ftp://iut-tice.ujf-grenoble.fr/cao/:src		\
#			ftp://ftp.lis.inpg.fr/uploads/kicad/:src	\
#			http://iut-tice.ujf-grenoble.fr/cao/:src
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry/${PORTNAME}
DISTFILES=		${PORTNAME}-${DISTVERSION}.tgz	\
			${PORTNAME}-sources--${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${PORTNAME}-sources--${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Schematic and PCB editing software

.if !defined(NOPORTDOCS)
DISTFILES+=	doc_components-${DOCVERSION}.tgz
DOCVERSION=	2007-07-02
.endif

WRKSRC=		${WRKDIR}/kicad-dev
MAKEFILE=	makefile.gtk
INSTALL_TARGET=	install-bin

USE_ZIP=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_WX=		2.8
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so
#TODO	Add support for Python.

INSTDIR=	${PORTNAME}
PLIST_SUB=	INSTDIR=${INSTDIR} OPSYS=${OPSYS}	\
		DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

DOS2CNV=	makefile.gtk makefile.include libs.linux
BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/konqueror)
RUN_DEPENDS+=	konqueror:${PORTSDIR}/x11/kdebase3
.else
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
.endif

post-extract:
.for df in ${DOS2CNV}
	for f in `${FIND} ${WRKSRC} -name ${df}`; do		\
		${CP} $$f $$f.dos &&					\
		${TR} -d '\r' < $$f.dos > $$f ;				\
	done
.endfor
	${CP} ${WRKSRC}/libs.linux ${WRKSRC}/libs.${OPSYS}
	${REINPLACE_CMD} -e 's|kicad/linux|${INSTDIR}/${OPSYS}|'	\
		${WRKSRC}/libs.${OPSYS}

pre-configure:
	for f in `${FIND} ${WRKSRC} -name ${MAKEFILE}` ; do		\
		${REINPLACE_CMD} -e 's|CC = gcc|#CC = gcc|'		\
			-e 's|LD = gcc|LD = ${CC}|'			\
			-e 's|LD = g++|LD = ${CXX}|'			\
			-e 's|-O2|${CFLAGS} -I${X11BASE}/include|'	\
			-e 's|wx-config|${WX_CONFIG}|'			\
			-e 's|LDFLAGS =|LDFLAGS += -L${X11BASE}/lib|'	\
			-e 's|libs.linux|libs.${OPSYS}|'		\
			-e 's|gcc -D|${CC} -D|' $$f ;			\
	done
	${REINPLACE_CMD} -e 's|kicad/linux|${INSTDIR}/${OPSYS}|'	\
		-e 's|/usr/share/kicad|${PREFIX}/${INSTDIR}|'		\
		-e 's|/usr/local|${PREFIX}|' ${WRKSRC}/common/gestfich.cpp
	${REINPLACE_CMD} -e 's|/usr/bin/xpdf|${X11BASE}/bin/xpdf|'	\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		${WRKSRC}/common/eda_doc.cpp

pre-install:
	${MKDIR} ${PREFIX}/${INSTDIR}/${OPSYS}/plugins ${DESKTOPDIR}
	(cd ${PREFIX} && ${TAR} -xzopf ${_DISTDIR}/${PORTNAME}-${DISTVERSION}.tgz)
	${SED} -e 's|Exec=/usr/local/kicad/linux|Exec=$(PREFIX)/bin|'		\
		-e 's|Icon=/usr/local/kicad/linux|Icon=${PREFIX}/${INSTDIR}|'	\
	< ${PREFIX}/${INSTDIR}/linux/kicad.desktop > ${DESKTOPDIR}/kicad.desktop
	${INSTALL_DATA} ${PREFIX}/${INSTDIR}/linux/kicad_icon.png ${PREFIX}/${INSTDIR}
	${RM} -rf ${EXTRAS2RM:S|^|${PREFIX}/${INSTDIR}/|}

post-install:
	${LN} -sf ${BINS:S|^|${PREFIX}/${INSTDIR}/${OPSYS}/|} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${TAR} -xf ${_DISTDIR}/doc_components-${DOCVERSION}.tgz \
		-C ${PREFIX}/${INSTDIR}/library
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${INSTDIR}/library/doc
.else
	${RM} -rf ${PREFIX}/${INSTDIR}/library/doc
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
