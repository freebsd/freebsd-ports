# New ports collection makefile for: libtai
# Date created:		15 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	libtai
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cr.yp.to/libtai/ \
		ftp://ftp.sunsite.auc.dk/disk1/qmail/ \
		ftp://ftp.task.gda.pl/mirror/mirror.qmail.org/koobera/pub/software/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A library for storing and manipulating dates and times in second/attosecond

USE_REINPLACE=	yes
USE_SIZE=	yes

ALL_TARGET=	it
INSTALLS_SHLIB=	yes
MAKE_ENV=	LIBVERSION="${LIBVERSION}"

PLIST_SUB=	LIBVERSION=${LIBVERSION} \
		LIBFILE=${LIBFILE}

MAN3=		caldate.3 caldate_mjd.3 caltime.3 caltime_tai.3 leapsecs.3 \
		tai.3 tai_now.3 tai_pack.3 taia.3 taia_now.3 taia_pack.3

# port information
LIBVERSION=	1
LIBFILE=	libtai
PROGRAM_FILES=	easter nowutc leapsecs yearcal
HEADER_FILES=	caldate.h caltime.h leapsecs.h tai.h taia.h uint64.h

do-configure:
	@${REINPLACE_CMD} -e "s!%%PREFIX%%!${PREFIX}!g" \
		${WRKSRC}/leapsecs.3 ${WRKSRC}/leapsecs_read.c
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} -fPIC -DPIC > ${WRKSRC}/conf-ccso

pre-install:
# correct header locations inside files
.for file in ${HEADER_FILES}
	@${REINPLACE_CMD} -E -e 's|(#include[[:space:]]+)"([^"]+)"|\1<libtai/\2>|' \
		${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${BINGRP} -m 644 \
		${WRKSRC}/leapsecs.dat ${PREFIX}/etc
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man3
.endfor
.for i in ${PROGRAM_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/${LIBFILE}.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBFILE}.so.${LIBVERSION} ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/${LIBFILE}.so.${LIBVERSION} \
		${PREFIX}/lib/${LIBFILE}.so
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/${PORTNAME}
.endfor

.include <bsd.port.mk>
