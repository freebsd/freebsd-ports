# New ports collection makefile for:    moscow-ml
# Version required:     1.4
# Date created:         26 July 1996
# Whom:                 chuckr
#
# $Id: Makefile,v 1.3 1996/07/29 22:33:14 asami Exp $
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
	for file in ${WRKDIR}/mosml/doc/*;do; \
	install -c -m 0444 -g bin -o bin $${file} ${PREFIX}/moscow_ml/doc;done
	(cd ${WRKDIR}/mosml/examples; \
	install -c -m 0444 -g bin -o bin README ${PREFIX}/moscow_ml/examples; \
	for sdirs in manual mls helpsigs calc pretty lexyacc;do; \
	mkdir -p ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	for file in $${sdirs}/*;do; \
	install -c -m 0444 -g bin -o bin $${file} ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	done; done;)
.endif

.include <bsd.port.mk>
