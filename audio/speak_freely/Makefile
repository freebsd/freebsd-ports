# New ports collection makefile for:    speak_freely
# Date created:         18 Apr 1996
# Whom:                 Mister X (to make portlint happy ;)
#
# $FreeBSD$
#

PORTNAME=	speak_freely
PORTVERSION=	7.6a
CATEGORIES=	audio security mbone
MASTER_SITES=	SF/speak-freely/speak-freely/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Voice communication over data networks

DEPRECATED=	Unmaintained, anachronistic, mail freebsd-ports@FreeBSD.org if interested
EXPIRATION=	2011-06-30

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm

UTILS=		sfspeaker sfmike sflwl sflaunch
DEMNS=		sfecho sflwld sfreflect
DDEMNS=		sfvod
SFLIB=		${PREFIX}/lib/speak_freely
MAN1=		${UTILS:S/$/.1/} ${DEMNS:S/$/.1/} ${DDEMNS:S/$/.1/}

MAKE_ENV=	"OPTFLAGS=${CFLAGS}"

do-install:
	if [ ! -d ${SFLIB} ]; then \
		${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755 ${SFLIB}; \
	fi
	cd ${WRKSRC}; \
	$(INSTALL_DATA) busy.au ring.au ${SFLIB}
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

.include <bsd.port.mk>
