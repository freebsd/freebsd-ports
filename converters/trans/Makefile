# New ports collection makefile for:    trans
# Version required:     1.11
# Date created:         6 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1996/07/13 22:41:46 ache Exp $
#

DISTNAME=       trans111
PKGNAME=        trans-1.11
CATEGORIES=     misc russian
MASTER_SITES=   ftp://ftp.informatik.uni-erlangen.de/pub/doc/ISO/charsets/

MAINTAINER=     ache@FreeBSD.org

LIBDIR= ${PREFIX}/lib/trans
ALL= transtab transiso checkiso transce8

do-install:
	cd ${WRKSRC} && $(INSTALL_PROGRAM) $(ALL) ${PREFIX}/bin
	cd ${WRKSRC} && \
	for i in $(ALL); do \
		$(INSTALL_MAN) $$i.man ${PREFIX}/man/cat1/$$i.1; \
	done
	-mkdir -p ${LIBDIR}/tables ${LIBDIR}/xlt ${LIBDIR}/doc
	cd ${WRKSRC} && \
	$(INSTALL_SCRIPT) checkall mkbintab mklist one iso ${LIBDIR}
	cd ${WRKSRC} && \
	$(INSTALL_DATA) iso10646 encoding.lis bin/trans.[ch] bin/trans.man \
		bin/utimbuf.h bin/utf.[ch] ${LIBDIR}
	cd ${WRKSRC}/tables && $(INSTALL_DATA) * ${LIBDIR}/tables
	cd ${WRKSRC}/xlt && $(INSTALL_DATA) * ${LIBDIR}/xlt
	cd ${WRKSRC}/doc && $(INSTALL_DATA) * ${LIBDIR}/doc


.include <bsd.port.mk>
