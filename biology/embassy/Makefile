# ex:ts=8
# New ports collection makefile for:	embassy
# Date created:		1.November.2004
# Whom:	      		Fernan Aguero <fernan@iib.unsamn.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	embassy
PORTVERSION=	2.10.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.uk.embnet.org/pub/EMBOSS/ \
		ftp://ftp.es.embnet.org/pub/software/emboss/EMBOSS/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/EMBOSS/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of contributed EMBOSS applications

LIB_DEPENDS=	nucleus.1:${PORTSDIR}/biology/emboss

USE_SUBMAKE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_MOTIF=	yes

OPTIONS=	DOMAINATRIX	"Protein structure and domain apps" on \
		EMNU		"EMBOSS simple menu" on \
		ESIM4		"Align cDNA/EST to genome" on \
		HMMER		"HMM alignment and searches" on \
		MEME		"Motif detection" on \
		MSE		"A multiple sequence screen editor" on \
		PHYLIP		"Phylogeny inference" on \
		TOPO		"Transmembrane display" on

CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"

EMBASSY_WRKDIR=		${WRKSRC}/EMBASSY
DOMAINATRIX_VERSION=	1.0.0
EMNU_VERSION=		1.05
ESIM4_VERSION=		1.0.0
HMMER_VERSION=		2.1.1
MEME_VERSION=		2.3.1
MSE_VERSION=		1.0.0
TOPO_VERSION=		1.0.0
PHYLIP_VERSION=		3.57c
EMBASSY_APPS=		DOMAINATRIX EMNU ESIM4 HMMER MEME MSE PHYLIP TOPO

.include <bsd.port.pre.mk>

.for app in ${EMBASSY_APPS}
.if !defined(WITHOUT_${app})
APPLIST+=	${app}
${app}_WRKSRC=	${EMBASSY_WRKDIR}/${app}-${${app}_VERSION}
${app}_DISTFILE=${app}-${${app}_VERSION}${EXTRACT_SUFX}
DISTFILES+=	${${app}_DISTFILE}
PLIST_${app}=	""
.else
PLIST_${app}=	"@comment "
.endif
PLIST_SUB+=	PLIST_${app}=${PLIST_${app}}
.endfor

do-extract:
.for app in ${APPLIST}
	@ ${MKDIR} ${EMBASSY_WRKDIR}
	@ cd ${EMBASSY_WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	  ${_DISTDIR}/${${app}_DISTFILE} ${EXTRACT_AFTER_ARGS}
	@ if [ `id -u` = 0 ]; then \
	    ${CHMOD} -R ug-s ${${app}_WRKSRC}; \
	    ${CHOWN} -R 0:0 ${${app}_WRKSRC}; \
	  fi
.endfor

.if !defined(WITHOUT_DOMAINATRIX)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/domainatrix-patch-Makefile.in
.endif

.if !defined(WITHOUT_EMNU)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/emnu-patch-Makefile.in
.endif

do-configure:
.for app in ${APPLIST}
	@ cd ${${app}_WRKSRC} && \
	  ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.endfor

do-build:
.for app in ${APPLIST}
	@ cd ${${app}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
.endfor

do-install:
.for app in ${APPLIST}
	@ cd ${${app}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
	  ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.post.mk>
