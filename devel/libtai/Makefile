# New ports collection makefile for: libtai
# Date created:		15 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	libtai
PORTVERSION=	0.60
CATEGORIES=	devel
MASTER_SITES=	http://cr.yp.to/libtai/ \
		ftp://mirror.pipex.net/pub/qmail/ \
		ftp://ftp.rifkin.technion.ac.il/pub/qmail/

MAINTAINER=	lioux@FreeBSD.org

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

do-configure:
	@${PERL} -pi -e "s!%%PREFIX%%!${PREFIX}!g" \
		${WRKSRC}/leapsecs.3 ${WRKSRC}/leapsecs_read.c
	@${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO} -fPIC -DPIC > ${WRKSRC}/conf-ccso

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

.include <bsd.port.mk>
