# New ports collection makefile for:    moscow-ml
# Version required:     1.4
# Date created:         26 July 1996
# Whom:                 chuckr
#
# $Id
#

DISTNAME=       mos14src
CATEGORIES+=	lang
PKGNAME=        moscow_ml
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/ \
		ftp://ftp.dcs.ed.ac.uk/pub/ml/Moscow/
MAINTAINER=	chuckr@freefall.FreeBSD.org
ALL_TARGET=	world
WRKSRC=		${WRKDIR}/mosml/src

post-install:
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/${PKGNAME}/doc
	mkdir -p ${PREFIX}/${PKGNAME}/examples
	for file in ${WRKDIR}/mosml/doc/*;do; \
	install -c -m 0444 -g bin -o bin $${file} ${PREFIX}/${PKGNAME}/doc;done
	(cd ${WRKDIR}/mosml/examples; \
	install -c -m 0444 -g bin -o bin README ${PREFIX}/${PKGNAME}/examples; \
	for sdirs in manual mls helpsigs calc pretty lexyacc;do; \
	mkdir -p ${PREFIX}/${PKGNAME}/examples/$${sdirs}; \
	for file in $${sdirs}/*;do; \
	install -c -m 0444 -g bin -o bin $${file} ${PREFIX}/${PKGNAME}/examples/$${sdirs}; \
	done; done;)
.endif

.include <bsd.port.mk>
