# New ports collection makefile for:    moscow-ml
# Version required:     1.4
# Date created:         26 July 1996
# Whom:                 chuckr
#
# $Id: Makefile,v 1.4 1996/07/30 01:24:55 chuckr Exp $
#

DISTNAME=       mos14src
PKGNAME=        moscow_ml-1.4
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/ \
		ftp://ftp.dcs.ed.ac.uk/pub/ml/Moscow/

MAINTAINER=	chuckr@freefall.FreeBSD.org

ALL_TARGET=	world
WRKSRC=		${WRKDIR}/mosml/src

post-install:
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/moscow_ml/doc
	mkdir -p ${PREFIX}/moscow_ml/examples
	for file in ${WRKDIR}/mosml/doc/*;do \
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/doc;done
	(cd ${WRKDIR}/mosml/examples; \
	${INSTALL_DATA} README ${PREFIX}/moscow_ml/examples; \
	for sdirs in manual mls helpsigs calc pretty lexyacc;do \
	mkdir -p ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	for file in $${sdirs}/*;do \
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	done; done;)
.endif

.include <bsd.port.mk>
