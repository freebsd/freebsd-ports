# New ports collection makefile for:	proftpd
# Version required:	1.0.3pl1
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $Id: Makefile,v 1.6 1998/12/17 10:43:52 asami Exp $
#

DISTNAME=	proftpd-1.2.0pre1
PKGNAME=	proftpd-1.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/

PATCH_SITES=	ftp://ftp.proftpd.org/patches/
PATCHFILES=	proftpd-1.2.0pre1-path_exploit3.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	stephane@lituus.fr

MAN1=	ftpcount.1
MAN8=	proftpd.8 ftpshut.8

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=/var/run \
			--with-modules=mod_ratio

post-configure:

	@${MV} ${WRKSRC}/src/proftpd.8 ${WRKSRC}/src/proftpd.8.pre_sed
	@${SED}	-e 's:/etc:${PREFIX}/etc:' \
		-e 's:/usr/sbin/proftpd:${PREFIX}/libexec/proftpd:' \
		-e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		< ${WRKSRC}/src/proftpd.8.pre_sed > ${WRKSRC}/src/proftpd.8

	@${MV} ${WRKSRC}/src/ftpshut.8 ${WRKSRC}/src/ftpshut.8.pre_sed
	@${SED}	-e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/etc:/var/run:' \
		< ${WRKSRC}/src/ftpshut.8.pre_sed > ${WRKSRC}/src/ftpshut.8

	@${MV} ${WRKSRC}/src/ftpcount.1 ${WRKSRC}/src/ftpcount.1.pre_sed
	@${SED}	-e 's:/usr/bin:${PREFIX}/bin:' \
		< ${WRKSRC}/src/ftpcount.1.pre_sed > ${WRKSRC}/src/ftpcount.1

do-install:

	@${INSTALL_PROGRAM} ${WRKSRC}/ftpcount ${PREFIX}/bin/ftpcount
	@${INSTALL_PROGRAM} ${WRKSRC}/proftpd ${PREFIX}/libexec/proftpd
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpshut ${PREFIX}/sbin/ftpshut
	@${INSTALL_MAN} ${WRKSRC}/src/ftpcount.1 ${PREFIX}/man/man1/ftpcount.1
	@${INSTALL_MAN} ${WRKSRC}/src/ftpshut.8 ${PREFIX}/man/man8/ftpshut.8
	@${INSTALL_MAN} ${WRKSRC}/src/proftpd.8 ${PREFIX}/man/man8/proftpd.8
	@if [ ! -f ${PREFIX}/etc/proftpd.conf ]; then \
		${INSTALL_SCRIPT} \
	${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf; \
	fi

.include <bsd.port.mk>
