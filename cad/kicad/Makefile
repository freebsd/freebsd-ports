# New ports collection makefile for:  kicad
# Date created:               29 November 2005
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		kicad
PORTVERSION=		20080825
CATEGORIES=		cad
#MASTER_SITES=		ftp://iut-tice.ujf-grenoble.fr/cao/:dat		\
#			ftp://ftp.lis.inpg.fr/uploads/kicad/:dat	\
#			http://iut-tice.ujf-grenoble.fr/cao/:dat	\
#			ftp://iut-tice.ujf-grenoble.fr/cao/:src		\
#			ftp://ftp.lis.inpg.fr/uploads/kicad/:src	\
#			http://iut-tice.ujf-grenoble.fr/cao/:src
MASTER_SITES=		SF
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}		\
			${PORTNAME}-library-${LIBVERSION}${EXTRACT_SUFX}	\
			${PORTNAME}-doc-${LIBVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=		${PORTNAME}
#EXTRACT_ONLY=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Schematic and PCB editing software

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

DOCVERSION=	1.1
LIBVERSION=	1.0
WRKSRC=		${WRKDIR}/kicad
MAKEFILE=	makefile.gtk
INSTALL_TARGET=	install-bin install-res

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_WX=		2.8
WX_UNICODE=	yes
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so
#TODO	Add support for Python.

PLIST_SUB=	OPSYS=${OPSYS}	\
		DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

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
	${CP} ${WRKSRC}/libs.linux ${WRKSRC}/libs.${OPSYS}

pre-configure:
	for f in `${FIND} ${WRKSRC} -name ${MAKEFILE}` ; do		\
		${REINPLACE_CMD} -e 's|CC = gcc|#CC = gcc|'		\
			-e 's|LD = gcc|LD = ${CC}|'			\
			-e 's|LD = g++|LD = ${CXX}|'			\
			-e 's|-O2|${CFLAGS} -I${LOCALBASE}/include|'	\
			-e 's|wx-config|${WX_CONFIG}|'			\
			-e 's|LDFLAGS =|LDFLAGS += -L${LOCALBASE}/lib|'	\
			-e 's|libs.linux|libs.${OPSYS}|'		\
			-e 's|gcc -D|${CC} -D|' $$f ;			\
	done
	${REINPLACE_CMD} -e 's|kicad/linux|kicad/${OPSYS}|'	\
		-e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|' ${WRKSRC}/common/gestfich.cpp
.for subdir in template internat
	${REINPLACE_CMD} -e 's|libs.linux|libs.${OPSYS}|'	\
		${WRKSRC}/${subdir}/makefile
.endfor
.for subdir in library modules
	${REINPLACE_CMD} -e 's|libs.linux|libs.${OPSYS}|'	\
		${WRKDIR}/kicad-library/${subdir}/makefile
.endfor
	${REINPLACE_CMD} -e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'	\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		${WRKSRC}/common/eda_doc.cpp

pre-install:
.for subdir in library modules
	${CP} -Rp ${WRKDIR}/kicad-library/${subdir} ${WRKSRC}/
.endfor

post-install:
	${MKDIR} ${DOCSDIR}/help ${DESKTOPDIR}
	(cd ${WRKDIR}/kicad-doc/doc/help	\
		&& ${COPYTREE_SHARE} \* ${DOCSDIR}/help)
	(cd ${WRKSRC}/resources/linux/opendesktop	\
		&& ${COPYTREE_SHARE} \* ${DESKTOPDIR})
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/demos && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
	${RM} ${EXAMPLESDIR}/CMakeLists.txt
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
