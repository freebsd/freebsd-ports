PORTNAME=	libtai
PORTVERSION=	0.60
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://cr.yp.to/libtai/ \
		ftp://ftp.sunsite.auc.dk/disk1/qmail/ \
		ftp://ftp.task.gda.pl/mirror/mirror.qmail.org/koobera/pub/software/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library for storing and manipulating dates and times

LICENSE=	UNLICENSE

CONFLICTS_INSTALL=	mess822

ALL_TARGET=	it
USES=		groff
USE_LDCONFIG=	yes
MAKE_ENV=	LIBVERSION="${LIBVERSION}"
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	LIBVERSION=${LIBVERSION} \
		LIBFILE=${LIBFILE}

MAN_FILES=	caldate.3 caldate_mjd.3 caltime.3 caltime_tai.3 leapsecs.3 \
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
# update leap seconds table
	@${CAT} ${FILESDIR}/leapsecs-update.txt >> ${WRKSRC}/leapsecs.txt

pre-install:
# correct header locations inside files
.for file in ${HEADER_FILES}
	@${REINPLACE_CMD} -E -e 's|(#include[[:space:]]+)"([^"]+)"|\1<libtai/\2>|' \
		${WRKSRC}/${file}
.endfor

post-build:
	@${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		${WRKSRC}/leapsecs < ${WRKSRC}/leapsecs.txt > \
		${WRKSRC}/leapsecs.dat

do-install:
	${INSTALL_DATA} ${WRKSRC}/leapsecs.dat ${STAGEDIR}${PREFIX}/etc
.for i in ${MAN_FILES}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/man/man3
.endfor
.for i in ${PROGRAM_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/${LIBFILE}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/${LIBFILE}.so.${LIBVERSION} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${LIBFILE}.so.${LIBVERSION} \
		${STAGEDIR}${PREFIX}/lib/${LIBFILE}.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.for file in ${HEADER_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor

.include <bsd.port.mk>
