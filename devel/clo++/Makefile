# New ports collection makefile for:	clo++
# Date created:				30 January 2001
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clo++
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://pmade.org/~pjones/software/clo++/download/

MAINTAINER=	kevlo@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GCC=	3.1
USE_PERL5=	yes
CONFGARGS=	--prefix ${PREFIX}
CONFGARGS+=	--xml2-config ${PREFIX}/bin/xml2-config

pre-configure:
	@(cd ${WRKSRC} && ${ENV} CXX=${CXX} ${PERL5} configure.pl ${CONFGARGS})

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/clo++
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/clo++
	@${INSTALL_DATA} ${WRKSRC}/docs/manual.txt ${PREFIX}/share/doc/clo++
.endif

.include <bsd.port.mk>
