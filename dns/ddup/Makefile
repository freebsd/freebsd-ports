# New ports collection makefile for:	ddup
# Version required:	2.0.4
# Date created:		30 September 1999
# Whom:			cjm2
#
# $FreeBSD$
#

DISTNAME=	ddup-2.2Dm
PKGNAME=	ddup-2.2
CATEGORIES=	net
MASTER_SITES=	ftp://ddup.sourceforge.net/pub/ddup/

MAINTAINER=	cjm2@altavista.net

MAN1=		ddup.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/ddup-2.2Dm

# Uncomment this if you want to enable debugging.
#DEBUG=		-g

pre-build:
	${ECHO} "char *file_name = \"${PREFIX}/etc/ddup.conf\";" > ${WRKSRC}/options.h

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c ddup.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c ddup_functions.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c getopt.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c getopt1.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c parse_config.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c parse_option.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -c update.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEBUG} -o ddup ddup.o ddup_functions.o getopt.o getopt1.o parse_config.o parse_option.o update.o ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ddup ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/testip ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ddup.1.gz ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/ddup
	${INSTALL_MAN} ${WRKSRC}/INSTALL-C ${PREFIX}/share/doc/ddup
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/ddup
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/ddup

post-install:
	strip ${PREFIX}/sbin/ddup
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
