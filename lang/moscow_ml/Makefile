# New ports collection makefile for:    moscow-ml
# Date created:         2 August 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	moscow_ml
PORTVERSION=	1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/ \
		ftp://ftp.dcs.ed.ac.uk/pub/ml/Moscow/
DISTNAME=	mos14src

MAINTAINER=	chuckr@freefall.FreeBSD.org

ALL_TARGET=	world MOSMLHOME=$(PREFIX)/moscow_ml
INSTALL_TARGET=	install MOSMLHOME=$(PREFIX)/moscow_ml
WRKSRC=		${WRKDIR}/mosml/src

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/moscow_ml/doc
	${MKDIR} ${PREFIX}/moscow_ml/doc/mosmllib
	${MKDIR} ${PREFIX}/moscow_ml/examples
	for file in ${WRKDIR}/mosml/doc/*;do \
	if [ -f $${file} ]; then\
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/doc;fi;done
	for file in ${WRKDIR}/mosml/doc/mosmllib/*;do \
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/doc/mosmllib;done
	(cd ${WRKDIR}/mosml/examples; \
	${INSTALL_DATA} README ${PREFIX}/moscow_ml/examples; \
	for sdirs in manual mls helpsigs calc pretty lexyacc;do \
	${MKDIR} ${PREFIX}/moscow_ml/examples/$${sdirs}; \
	for file in $${sdirs}/*;do \
	if [ -f $${file} ]; then\
	${INSTALL_DATA} $${file} ${PREFIX}/moscow_ml/examples/$${sdirs}; fi; \
	done; done;)
.endif
	for file in $(PREFIX)/moscow_ml/bin/*;do \
	if [ -f $${file} ]; then\
	$(LN) -sf $${file} $(PREFIX)/bin;fi;done

.include <bsd.port.mk>
