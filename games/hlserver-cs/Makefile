# New ports collection makefile for:	Counter Strike Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	CS
PORTVERSION=	1.1b
CATEGORIES=	games linux
MASTER_SITES=	http://hex.databits.net/~pat/ \
		ftp://ftp.icrontic.com/pub/ \
		http://flf.playnet.com/
DISTNAME=	cs_11b_full
EXTRACT_ONLY=	

MAINTAINER=	pat@databits.net

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base \
		hlds_l:${PORTSDIR}/games/halflifeserver

NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
PREFIX=		/compat/linux
WRKSRC=		${WRKDIR}/hlds_l
EXTRACT_ONLY_1=	cs_11b_full.tar.gz

HLDSDIR=	/usr/games/hlds_l

do-install:
	@cd ${PREFIX}${HLDSDIR} ;\
	for file in ${EXTRACT_ONLY_1}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$${file} ${EXTRACT_AFTER_ARGS}) ;\
		then \
			exit 1 ;\
		fi \
	done

.include <bsd.port.mk>
