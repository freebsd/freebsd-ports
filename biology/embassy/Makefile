# ex:ts=8
# New ports collection makefile for:	embassy
# Date created:		1.November.2004
# Whom:	      		Fernan Aguero <fernan@iib.unsamn.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	embassy
PORTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://emboss.open-bio.org/pub/EMBOSS/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/EMBOSS/
DIST_SUBDIR=	emboss

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of contributed EMBOSS applications

LIB_DEPENDS=	nucleus.6:${PORTSDIR}/biology/emboss

PREFIX?=	${LOCALBASE}/emboss
NO_MTREE=	yes
USE_SUBMAKE=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_MOTIF=	yes
USE_LDCONFIG=	yes

OPTIONS=	DOMAINATRIX	"Protein domain apps" on \
		DOMALIGN	"Protein domain apps" on \
		DOMSEARCH	"Protein domain apps" on \
		SIGNATURE	"Protein domain apps" on \
		STRUCTURE	"Protein domain apps" on \
		EMNU		"EMBOSS simple menu" on \
		ESIM4		"Align cDNA/EST to genome" on \
		HMMER		"HMM alignment and searches" on \
		MEMENEW		"Motif detection" on \
		MSE		"A multiple sequence screen editor" on \
		MYEMBOSS	"Examples for developers of EMBOSS apps" on \
		PHYLIPNEW	"Phylogeny inference" on \
		TOPO		"Transmembrane display" on \
		VIENNA		"RNA folding" on \
		MIRA		"Whole Genome shotgun and EST assembler" on \
		IPRSCAN		"InterPro scan" on \
		CBSTOOLS	"CBS Tools" on

CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/emboss/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib -L${LOCALBASE}/emboss/lib"

EMBASSY_WRKDIR=		${WRKSRC}/EMBASSY
DOMAINATRIX_VERSION=	0.1.0
EMNU_VERSION=		1.05
ESIM4_VERSION=		1.0.0
HMMER_VERSION=		2.3.2
MEMENEW_VERSION=	0.1.0
MSE_VERSION=		1.0.0
TOPO_VERSION=		1.0.0
PHYLIPNEW_VERSION=	3.67
DOMALIGN_VERSION=	0.1.0
DOMSEARCH_VERSION=	0.1.0
SIGNATURE_VERSION=	0.1.0
STRUCTURE_VERSION=	0.1.0
MYEMBOSS_VERSION=	6.0.0
VIENNA_VERSION=		1.7.2
MIRA_VERSION=		2.8.2
IPRSCAN_VERSION=	4.3.1
CBSTOOLS_VERSION=	1.0.0
EMBASSY_APPS=		DOMAINATRIX EMNU ESIM4 HMMER MEMENEW MSE PHYLIPNEW \
			TOPO DOMALIGN DOMSEARCH SIGNATURE STRUCTURE MYEMBOSS \
			VIENNA MIRA IPRSCAN CBSTOOLS

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
