# New ports collection makefile for:	primer3
# Date created:				25 February 2002
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	primer3
PORTVERSION=	1.0.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Primer3 helps to choose primers for PCR reactions

WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCUMENTS=	README.${PORTNAME}_${PORTVERSION}.txt example

post-patch:
	@${REINPLACE_CMD} \
		-e 's#^CFLAGS.*#CFLAGS  += \$$\(CC_OPTS\)#;' \
		-e 's#CC_OPTS = -g#CC_OPTS =#;' \
		-e 's#LDFLAGS = -g#LDFLAGS ?=#;' \
		-e 's#^WHITEHEAD_SPECIFIC_HACK.*##;' \
		${WRKDIR}/${DISTNAME}/src/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/primer3_core ${PREFIX}/bin/primer3
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Copyright.txt ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCUMENTS}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${file} ${DOCSDIR}
.endfor
	@${RM} -rf ${WRKDIR}/${DISTNAME}/test/primer*_list_tmp
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKDIR}/${DISTNAME}/test && ${FIND} * | ${CPIO} --quiet \
		-pdum -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${DATADIR}/Copyright.txt

.include <bsd.port.mk>
