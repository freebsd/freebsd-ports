# New ports collection makefile for:	primer3
# Date created:				25 February 2002
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	primer3
PORTVERSION=	0.9
CATEGORIES=	biology
MASTER_SITES=	http://www-genome.wi.mit.edu/ftp/distribution/software/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}_test

MAINTAINER=	tonym@biolateral.com.au

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CPIO=		cpio --quiet -pdum -R
DOCUMENTS=	README example
CGI_EXAMPLES=	primer3_www.cgi		primer3_www_help.html \
		primer3_www_results.cgi	primer3_www_results_help.html

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
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Copyright ${DATADIR}
.for file in ${CGI_EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCUMENTS}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${file} ${DOCSDIR}
.endfor
	@${RMDIR} ${WRKDIR}/${DISTNAME}/test/primer*_list_tmp
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKDIR}/${DISTNAME}/test && ${FIND} * | \
		${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${DATADIR}/Copyright

.include <bsd.port.mk>
