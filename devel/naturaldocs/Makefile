# ex:ts=8
# Ports collection makefile for:	NaturalDocs
# Date created:			Feb 27, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	naturaldocs
PORTVERSION=	1.34
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	NaturalDocs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible, multi-language source code documentation generator

USE_ZIP=	yes
USE_PERL5_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/NaturalDocs
PLIST_FILES=	bin/NaturalDocs

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs ${PREFIX}/bin
	@${MKDIR} ${SITE_PERL}/NaturalDocs
	@cd ${WRKSRC}/Modules/NaturalDocs && \
		${FIND} * -type d -exec ${MKDIR} ${SITE_PERL}/NaturalDocs/{} \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} {} ${SITE_PERL}/NaturalDocs/{} \;
	@${FIND} ${SITE_PERL}/NaturalDocs -type f | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/NaturalDocs -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/Help && \
		${FIND} * -type d -exec ${MKDIR} ${DOCSDIR}/{} \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${FIND} ${DOCSDIR} -type f | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
