# New ports collection makefile for:    jgnat-doc
# Date created:         05 Sept 2001
# Whom:                 John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	jgnat-doc
PORTVERSION=	1.1p
CATEGORIES=	lang java
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cdrom.com/pub/languages/ada/compiler/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://wuarchive.wustl.edu/languages/ada/compiler/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cs.kuleuven.ac.be/pub/Ada-Belgium/mirrors/cs.nyu.edu/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cs.tu-berlin.de/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/mirror/cs.nyu.edu/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.lip6.fr/pub/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.cnam.fr/pub/Ada/PAL/compiler/gnat/jgnat/jgnat-1.1p/split-1.1p/ \
		ftp://ftp.fss.bme.hu/pub/ada/gnat/jgnat/jgnat-1.1p/split-1.1p/
PKGNAMESUFFIX=	-${DOCFORMAT}
DISTNAME=	jgnat-${PORTVERSION}-doc
EXTRACT_SUFX=	.tgz

MAINTAINER=	coop9211@uidaho.edu

WRKSRC=		${WRKDIR}/${DISTNAME:S/-doc$//}/doc
NO_BUILD=	yes
PLIST=		${MASTERDIR}/pkg-plist_${DOCFORMAT}
PKGMESSAGE=	${MASTERDIR}/pkg-message_${DOCFORMAT}

DOCFORMAT?=	html
DOCSDIR=	${PREFIX}/share/doc/jgnat/${DOCFORMAT}

SEC_LABEL=	"Programming & development tools."
INSTALL_INFO=	install-info --section=${SEC_LABEL}
UG_LABEL=	"* Jgnat_ug: (jgnat_ug).            JGNAT User Guide."

PLIST_SUB=	SEC_LABEL=${SEC_LABEL} UG_LABEL=${UG_LABLE}

.include <bsd.port.pre.mk>

.if ${DOCFORMAT} != "html" && ${DOCFORMAT} != "info" && ${DOCFORMAT} != "ps" && ${DOCFORMAT} != "txt"
.BEGIN:
	@${ECHO} "ERROR: invalid value for DOCFORMAT: \"${DOCFORMAT}\""
	@${ECHO} "Possible values are:  html, info, ps, and txt."
	@${FALSE}
.endif

pre-install:
	@${CP} ${PKGDIR}/pkg-plist_${DOCFORMAT} ${WRKDIR}
	@${CP} ${PKGDIR}/pkg-message_${DOCFORMAT} ${WRKDIR}

do-install:
.if !defined(NOPORTDOCS)
.if ${DOCFORMAT} == "info"
	@${MKDIR} ${PREFIX}/info
	@${INSTALL_MAN} ${WRKSRC}/jgnat_ug.info* ${PREFIX}/info
	@if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' \/usr\/share\/info/dir > ${PREFIX}/info/dir; \
	fi
	@${INSTALL_INFO} --item=${UG_LABEL} ${PREFIX}/info/jgnat_ug.info ${PREFIX}/info/dir
.else
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/jgnat_ug.${DOCFORMAT} ${DOCSDIR}
.endif
.endif # !defined(NOPORTDOCS)

post-install:
.if !defined (NOPORTDOCS)
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:/usr/local:${PREFIX}:'
.endif

.include <bsd.port.post.mk>
