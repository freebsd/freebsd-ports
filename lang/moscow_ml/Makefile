# New ports collection makefile for:    moscow-ml
# Version required:     1.4
# Date created:         26 July 1996
# Whom:                 chuckr
#
# $Id: Makefile,v 1.7 1996/11/21 09:32:45 asami Exp $
#

DISTNAME=       mos14src
PKGNAME=        moscow_ml-1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/ \
		ftp://ftp.dcs.ed.ac.uk/pub/ml/Moscow/

MAINTAINER=	chuckr@freefall.FreeBSD.org

BROKEN=		install
ALL_TARGET=	world
WRKSRC=		${WRKDIR}/mosml/src

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/moscow_ml/doc
	${MKDIR} ${PREFIX}/moscow_ml/examples
	for file in ${WRKDIR}/mosml/doc/*;do \
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/doc;done
	(cd ${WRKDIR}/mosml/examples; \
	${INSTALL_DATA} README ${PREFIX}/moscow_ml/examples; \
	for sdirs in manual mls helpsigs calc pretty lexyacc;do \
	${MKDIR} ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	for file in $${sdirs}/*;do \
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	done; done;)
.endif

.include <bsd.port.mk>
