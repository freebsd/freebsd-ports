# New ports collection Makefile for:	babel
# Date created:		Dec 4 1997
# Whom:			frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	babel
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	biology converters
MASTER_SITES=	http://smog.com/chem/babel/files/ \
		http://www.ccl.net/cca/software/UNIX/babel/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts among various molecular file formats

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

post-build:
	${SED} -e 's%@PREFIX@%${PREFIX}%g' \
		${FILESDIR}/babel.sh >${WRKSRC}/babel.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/babel ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/babel.sh ${PREFIX}/bin/babel
	@${MKDIR} ${PREFIX}/share/babel
	${INSTALL_DATA} ${WRKSRC}/*.lis ${PREFIX}/share/babel
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${DOCSDIR}
.endif

.include <bsd.port.mk>
