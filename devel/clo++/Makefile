# New ports collection makefile for:	clo++
# Date created:				30 January 2001
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clo++
PORTVERSION=	0.6.3
CATEGORIES=	devel
MASTER_SITES=	http://pmade.org/~pjones/software/clo++/download/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Command line parser generator

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

BROKEN=		Does not compile

USE_GCC=	3.2
USE_PERL5=	yes
CONFGARGS=	--prefix ${PREFIX}
CONFGARGS+=	--xml2-config ${PREFIX}/bin/xml2-config

MAN1=		clo++.1

pre-configure:
	@(cd ${WRKSRC} && ${ENV} CXX=${CXX} ${PERL5} configure.pl ${CONFGARGS})

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/clo++
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
