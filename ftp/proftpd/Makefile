# New ports collection makefile for:	proftpd
# Version required:	1.0.0
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $Id$
#

DISTNAME=	proftpd-1.0.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/

MAINTAINER=	stephane@lituus.fr

MAN1=	ftpwho.1 ftpcount.1
MAN8=	proftpd.8 ftpshut.8

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"

#
# Ugly but "configure --prefix=..." doesn't seem work :(
# So, do a "sed" to set prefix to $PREFIX
#
# Ugly again, do a "sed" to set the config dir to ${PREFIX}/etc
#

pre-build:
	${SED} -e "s:^prefix=\/usr:prefix=${PREFIX}:" < ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.tmp
	${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

	${SED} -e "s:^etcdir=\/etc:etcdir=${PREFIX}\/etc:" < ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.tmp
	${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

	${SED} -e "s:^libexecdir=\/libexec:libexecdir=${PREFIX}\/libexec:" < ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.tmp
	${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

	${SED} -e 's:\/etc\/proftpd\.conf:${PREFIX}\/etc\/proftpd.conf:' < ${WRKSRC}/config.h > ${WRKSRC}/config.h.tmp
	${MV} ${WRKSRC}/config.h.tmp ${WRKSRC}/config.h

post-install:
	strip ${PREFIX}/bin/ftpcount
	strip ${PREFIX}/bin/ftpwho
	strip ${PREFIX}/libexec/proftpd
	strip ${PREFIX}/sbin/ftpshut

.include <bsd.port.mk>
