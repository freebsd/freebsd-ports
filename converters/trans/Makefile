# New ports collection makefile for:    trans
# Version required:     1.20
# Date created:         6 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       trans120
PKGNAME=        trans-1.20
CATEGORIES=     converters russian
MASTER_SITES=   http://www.kostis.net/freeware/

MAINTAINER=     ache@FreeBSD.org

LIBDIR= ${PREFIX}/lib/trans
ALL= transhtm transiso transce8 transtab checkiso checkuni

do-install:
	cd ${WRKSRC}/src && $(INSTALL_PROGRAM) $(ALL) ${PREFIX}/bin
	cd ${WRKSRC}/src && \
	for i in $(ALL); do \
		$(INSTALL_MAN) $$i.man ${PREFIX}/man/cat1/$$i.1; \
	done
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${LIBDIR}/cedf ${LIBDIR}/xlt ${LIBDIR}/doc ${LIBDIR}/bin \
		${LIBDIR}/src
	cd ${WRKSRC}/src && \
		$(INSTALL_SCRIPT) checkall chkuni mkhtml mklist mkxlt \
		${LIBDIR}/src
	cd ${WRKSRC} && \
		$(INSTALL_DATA) README encoding.lis ${LIBDIR}
	cd ${WRKSRC}/src && \
		$(INSTALL_DATA) datatype.h ${LIBDIR}/src
	cd ${WRKSRC}/bin && \
		$(INSTALL_DATA) one trans.[ch] trans.man utimbuf.h utf.[ch] \
		${LIBDIR}/bin
	cd ${WRKSRC}/cedf && $(INSTALL_DATA) * ${LIBDIR}/cedf
	cd ${WRKSRC}/doc && $(INSTALL_DATA) * ${LIBDIR}/doc
	cd ${WRKSRC}/xlt && $(INSTALL_DATA) * ${LIBDIR}/xlt

.include <bsd.port.mk>
