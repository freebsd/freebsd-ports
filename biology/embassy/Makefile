# Created by: Fernan Aguero <fernan@iib.unsamn.edu.ar>
# $FreeBSD$

PORTNAME=	embassy
PORTVERSION=	6.2.0
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	ftp://emboss.open-bio.org/pub/EMBOSS/
DIST_SUBDIR=	emboss

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Collection of contributed EMBOSS applications

LIB_DEPENDS=	nucleus.6:${PORTSDIR}/biology/emboss

PREFIX?=	${LOCALBASE}/emboss
NO_MTREE=	yes
USE_SUBMAKE=	yes
USES=		iconv gmake motif
GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOMAINATRIX DOMALIGN DOMSEARCH SIGNATURE STRUCTURE \
		EMNU ESIM4 HMMER MEMENEW MSE MYEMBOSS PHYLIPNEW TOPO \
		VIENNA MIRA IPRSCAN CBSTOOLS

DOMAINATRIX_DESC=	Protein domain apps
DOMALIGN_DESC=	Protein domain apps
DOMSEARCH_DESC=	Protein domain apps
SIGNATURE_DESC=	Protein domain apps
STRUCTURE_DESC=	Protein domain apps
EMNU_DESC=	EMBOSS simple menu
ESIM4_DESC=	Align cDNA/EST to genome
HMMER_DESC=	HMM alignment and searches
MEMENEW_DESC=	Motif detection
MSE_DESC=	A multiple sequence screen editor
MYEMBOSS_DESC=	Examples for developers of EMBOSS apps
PHYLIPNEW_DESC=	Phylogeny inference
TOPO_DESC=	Transmembrane display
VIENNA_DESC=	RNA folding
MIRA_DESC=	Whole Genome shotgun and EST assembler
IPRSCAN_DESC=	InterPro scan
CBSTOOLS_DESC=	CBS Tools

OPTIONS_DEFAULT=	DOMAINATRIX DOMALIGN DOMSEARCH SIGNATURE STRUCTURE \
		EMNU ESIM4 HMMER MEMENEW MSE MYEMBOSS PHYLIPNEW TOPO \
		VIENNA MIRA IPRSCAN CBSTOOLS

CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/emboss/include
LDFLAGS+=	-L${PREFIX}/lib -L${LOCALBASE}/lib -L${LOCALBASE}/emboss/lib

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

EMBASSY_WRKDIR=		${WRKSRC}/EMBASSY
DOMAINATRIX_VERSION=	0.1.0
EMNU_VERSION=		1.05
ESIM4_VERSION=		1.0.0
HMMER_VERSION=		2.3.2
MEMENEW_VERSION=	4.0.0
MSE_VERSION=		3.0.0
TOPO_VERSION=		2.0.0
PHYLIPNEW_VERSION=	3.69
DOMALIGN_VERSION=	0.1.0
DOMSEARCH_VERSION=	0.1.0
SIGNATURE_VERSION=	0.1.0
STRUCTURE_VERSION=	0.1.0
MYEMBOSS_VERSION=	6.2.0
VIENNA_VERSION=		1.7.2
MIRA_VERSION=		2.8.2
IPRSCAN_VERSION=	4.3.1
CBSTOOLS_VERSION=	1.0.0
EMBASSY_APPS=		DOMAINATRIX EMNU ESIM4 HMMER MEMENEW MSE PHYLIPNEW \
			TOPO DOMALIGN DOMSEARCH SIGNATURE STRUCTURE MYEMBOSS \
			VIENNA MIRA IPRSCAN CBSTOOLS

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.for app in ${EMBASSY_APPS}
.if ${PORT_OPTIONS:M${app}}
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

post-extract:
	@${REINPLACE_CMD} -e 's#emboss_doc##g' ${EMBASSY_WRKDIR}/MIRA-2.8.2/Makefile.in

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'

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
