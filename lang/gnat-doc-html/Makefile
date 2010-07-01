# New ports collection makefile for:    gnat-doc
# Date created:         4 Sept 2001
# Whom:                 John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	gnat-doc
PORTVERSION=	3.15p
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/%SUBDIR%/ \
		ftp://ftp.cdrom.com/pub/languages/ada/compiler/gnat/%SUBDIR%/ \
		ftp://wuarchive.wustl.edu/languages/ada/compiler/gnat/%SUBDIR%/ \
		ftp://ftp.cs.kuleuven.ac.be/pub/Ada-Belgium/mirrors/cs.nyu.edu/pub/gnat/%SUBDIR%/ \
		ftp://ftp.cs.tu-berlin.de/pub/gnat/%SUBDIR%/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/mirror/cs.nyu.edu/pub/gnat/%SUBDIR%/ \
		ftp://ftp.lip6.fr/pub/gnat/%SUBDIR%/ \
		ftp://ftp.cnam.fr/pub/Ada/PAL/compiler/gnat/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMESUFFIX=	-${DOCFORMAT}
DISTNAME=	gnat-${PORTVERSION}-unx-docs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation for the GNAT compiler

WRKSRC=		${WRKDIR}/gnat-${PORTVERSION}-unx-docs
NO_BUILD=	yes
PLIST=		${MASTERDIR}/pkg-plist_${DOCFORMAT}
SUB_FILES=	pkg-message_${DOCFORMAT}

DOCFORMAT?=	html

SEC_LABEL=	"Programming & development tools."
INSTALL_INFO=	install-info --section=${SEC_LABEL}
ARM_LABEL=	"* ARM95: (arm95).                  Ada 95 Annotated Reference Manual."
GCC_LABEL=	"* Adagcc: (gcc).                   GNAT gcc 2.8.1 compiler reference."
RM_LABEL=	"* Gnat_rm: (gnat_rm).              GNAT Reference Manual."
UG_LABEL=	"* Gnat_ug: (gnat_ug).              GNAT User Guide."

PLIST_SUB=	SEC_LABEL=${SEC_LABEL} ARM_LABEL=${ARM_LABEL} \
		GCC_LABEL=${GCC_LABEL} RM_LABEL=${RM_LABEL} \
		UG_LABEL=${UG_LABEL}

.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "info" && ${DOCFORMAT} != "ps" && ${DOCFORMAT} != "texi" && ${DOCFORMAT} != "txt"
.BEGIN:
	@${ECHO} "ERROR: invalid value for DOCFORMAT: \"${DOCFORMAT}\""
	@${ECHO} "Possible values are:  html, info, ps, texi,"
	@${ECHO} "and txt."
	@${FALSE}
.endif

.ifdef NOPORTDOCS
IGNORE=		this port only contains documentation, please undefine NOPORTDOCS and try again
.endif

do-install:
.if ${DOCFORMAT} == "info"
	@${MKDIR} ${PREFIX}/info
	@${INSTALL_MAN} ${WRKSRC}/${DOCFORMAT}/* ${PREFIX}/info
	@${INSTALL_INFO} --item=${ARM_LABEL} ${PREFIX}/info/arm95.info ${PREFIX}/info/dir
	@${INSTALL_INFO} --item=${GCC_LABEL} ${PREFIX}/info/gcc.info ${PREFIX}/info/dir
	@${INSTALL_INFO} --item=${RM_LABEL} ${PREFIX}/info/gnat_rm.info ${PREFIX}/info/dir
	@${INSTALL_INFO} --item=${UG_LABEL} ${PREFIX}/info/gnat_ug.info ${PREFIX}/info/dir
.else
	@${MKDIR} ${DOCSDIR}/${DOCFORMAT}
	@${INSTALL_MAN} ${WRKSRC}/${DOCFORMAT}/* ${DOCSDIR}/${DOCFORMAT}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
