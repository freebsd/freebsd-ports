# New ports collection makefile for:    trans
# Version required:     1.12
# Date created:         6 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1997/04/26 23:55:24 asami Exp $
#

DISTNAME=       trans112
PKGNAME=        trans-1.12
CATEGORIES=     converters russian
MASTER_SITES=   http://www.kostis.net/freeware/

MAINTAINER=     ache@FreeBSD.org

LIBDIR= ${PREFIX}/lib/trans
ALL= transtab transiso checkiso transce8

post-build:
	cd ${WRKSRC} && ${MAKE} bintab

do-install:
	cd ${WRKSRC} && $(INSTALL_PROGRAM) $(ALL) ${PREFIX}/bin
	cd ${WRKSRC} && \
	for i in $(ALL); do \
		$(INSTALL_MAN) $$i.man ${PREFIX}/man/cat1/$$i.1; \
	done
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${LIBDIR}/tables ${LIBDIR}/xlt ${LIBDIR}/doc ${LIBDIR}/bin
	cd ${WRKSRC} && \
		$(INSTALL_SCRIPT) checkall mkbintab mklist one iso ${LIBDIR}
	cd ${WRKSRC} && \
		$(INSTALL_DATA) iso10646 encoding.lis datatype.h ${LIBDIR}
	cd ${WRKSRC}/bin && \
		$(INSTALL_DATA) trans.[ch] trans.man utimbuf.h utf.[ch] \
		${LIBDIR}/bin
	cd ${WRKSRC}/tables && $(INSTALL_DATA) * ${LIBDIR}/tables
	cd ${WRKSRC}/doc && $(INSTALL_DATA) * ${LIBDIR}/doc
	cd ${WRKSRC}/xlt && $(INSTALL_DATA) * ${LIBDIR}/xlt


.include <bsd.port.mk>
