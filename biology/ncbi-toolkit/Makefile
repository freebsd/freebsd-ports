# New ports collection makefile for:	NCBI
# Date created:         03 April 2000
# Whom:                 tonym
#
# $FreeBSD$
#

PORTNAME=	ncbi-toolkit
PORTVERSION=	2002.04.26
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools/old/${PORTVERSION:S/.//g}/
DISTNAME=	ncbi

MAINTAINER=	tonym@biolateral.com.au

USE_MOTIF=	yes
USE_REINPLACE=	yes

#
# In the files directory we have:
#

DUMMYMAKE=	Makefile
PLATFORMDIR=	${WRKSRC}/platform
BUILDSCRIPT=	${WRKSRC}/make/makedis.csh

DOCDIR=		${PREFIX}/share/doc/${PORTNAME}
CPIO=		cpio --quiet -pdum -R

#
# Thus ends the definitions.
#
# Now we need a dummy top level Makefile as NCBI has scripts that need to
# run from point above ncbi hierachy.
#

pre-configure:
	@${CP} ${FILESDIR}/${DUMMYMAKE} ${WRKSRC}
	@${CP} ${FILESDIR}/freebsd.ncbi.mk ${PLATFORMDIR}
	@${REINPLACE_CMD} -e 's#NetBSD#FreeBSD#;'  -e 's#netbsd#freebsd#' ${BUILDSCRIPT}

post-install:
	@${MKDIR} ${DATADIR}
	@for file in ${WRKSRC}/data/*; do \
		${INSTALL_DATA} $$file ${DATADIR}; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@cd ${WRKSRC}/doc && find * | \
	  ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCDIR}
.endif
	@${SED} -e "s#%%PREFIX%%#${PREFIX}#" ${PKGMESSAGE}

.include <bsd.port.mk>
