# New ports collection makefile for:	fastDNAml
# Date created:		12 Oct 2000
# Whom:	      		Motomichi Matsuzaki <mzaki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	fastdnaml
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://www.life.illinois.edu/gary/programs/fastDNAml/
DISTNAME=	fastDNAml_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Faster DNAML, makes phylogenetic trees using maximum likelihood

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/GNU_GENERAL_PUBLIC_LICENSE

BUILD_WRKSRC=	${WRKSRC}/source

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/fastDNAml ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
