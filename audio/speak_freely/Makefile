# New ports collection makefile for:    speak_freely
# Original WWW site: http://www.fourmilab.ch/speakfree/unix/index.html
# Version required:     6.1b
# Date created:         18 Apr 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/11/11 23:17:38 ache Exp $
#

DISTNAME=       speak_freely-6.1b
CATEGORIES=     mbone audio security
MASTER_SITES=   http://www.fourmilab.ch/speakfree/unix/

MAINTAINER=     ache@FreeBSD.ORG

LIB_DEPENDS=    gsm\\.1\\.0:${PORTSDIR}/audio/gsm

UTILS=   sfspeaker sfmike sflwl
DEMNS=   sfecho sflwld
DDEMNS=  sfvod
SFLIB=   ${PREFIX}/lib/speak_freely

do-install:
	if [ ! -d ${SFLIB} ]; then \
		install -d -o ${BINOWN} -g ${BINGRP} -m 755 ${SFLIB}; \
	fi
	cd ${WRKSRC}; \
	$(INSTALL_DATA) ring.au ${SFLIB}
	cd ${WRKSRC}; \
	for p in ${UTILS}; do \
		$(INSTALL_PROGRAM) $$p ${PREFIX}/bin; \
		$(INSTALL_MAN) $$p.1 ${PREFIX}/man/man1; \
	done;
	cd ${WRKSRC}; \
	for p in ${DEMNS}; do \
		$(INSTALL_PROGRAM) $$p ${PREFIX}/sbin; \
		$(INSTALL_MAN) $$p.1 ${PREFIX}/man/man1; \
	done;
	cd ${WRKSRC}; \
	for p in ${DDEMNS}; do \
		$(INSTALL_SCRIPT) $$p ${PREFIX}/sbin; \
		$(INSTALL_MAN) $$p.1 ${PREFIX}/man/man1; \
	done;
.if !defined(NOMANCOMPRESS)
	for p in ${UTILS} ${DEMNS} ${DDEMNS}; do \
		gzip -9nf ${PREFIX}/man/man1/$$p.1; \
	done
.endif

.include <bsd.port.mk>
