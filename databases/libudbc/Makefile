# New ports collection makefile for:	libudbc
# Date created:        22 Oct 2001
# Whom:                Eugene Grosbein <eugen@grosbein.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	libudbc
PORTVERSION=	4.1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openlinksw.com/open41/ \
		ftp://www.kuzbass.ru/pub/FreeBSD/ports/distfiles/
DISTNAME=	f6kuzzzz
EXTRACT_SUFX=	.taz

MAINTAINER=	eugen@grosbein.pp.ru
COMMENT=	Openlink UDBC SDK

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386

BROKEN=		"Distfile has disappeared"
RESTRICTED=	'Downloading and redistribution terms are unclear'

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/udbcsdk/examples/udbctest ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/libudbc.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbcext.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbcimpl.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbcodb3.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbcodbc.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbcprto.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbcsag.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/include/udbc/udbctype.h ${PREFIX}/include/udbc
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/lib/libudbc.a ${PREFIX}/lib
	@${INSTALL} -c -o ${SHAREOWN} -g ${SHAREGRP} -m 755  ${WRKDIR}/udbcsdk/lib/libudbc.la ${PREFIX}/lib
	@${INSTALL} -c -o ${LIBOWN} -g ${LIBGRP} -m 755 ${WRKDIR}/udbcsdk/lib/libudbc.so ${PREFIX}/lib
	@${LN} -f ${PREFIX}/lib/libudbc.so ${PREFIX}/lib/libudbc.so.3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/doc/udbc.doc ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/doc/udbc.ini ${PREFIX}/share/doc/${PORTNAME}/udbc.ini.sample
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${SED} "s,../,${PREFIX}/," <${WRKDIR}/udbcsdk/examples/Makefile >${PREFIX}/share/examples/${PORTNAME}/Makefile
	@${INSTALL_DATA} ${WRKDIR}/udbcsdk/examples/udbctest.c ${PREFIX}/share/examples/${PORTNAME}

post-install:
	@${SED} "s'PREFIX'${PREFIX}'" <pkg-message
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
IGNORE=		"Systems prior to 4.x are not supported"
.endif

.include <bsd.port.post.mk>
