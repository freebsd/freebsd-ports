# New ports collection makefile for:	proftpd
# Version required:	1.2.0pl9
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

DISTNAME=	proftpd-1.2.0pre9
PKGNAME=	proftpd-1.2.0p9
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.tos.net/pub/proftpd/

MAINTAINER=	mharo@FreeBSD.org

MAN1=	ftpcount.1 ftpwho.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpshut.8

USE_GMAKE=	yes
USE_AUTOCONF=	yes

CONFIGURE_ARGS=	--localstatedir=/var/run

MODULES?=	mod_ratio

CONFIGURE_ARGS+= --with-modules=${MODULES}

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES}"

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
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpwho ${PREFIX}/bin/ftpwho
	@${INSTALL_PROGRAM} ${WRKSRC}/proftpd ${PREFIX}/libexec/proftpd
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpshut ${PREFIX}/sbin/ftpshut
	@${INSTALL_MAN} ${WRKSRC}/src/ftpcount.1 ${PREFIX}/man/man1/ftpcount.1
	@${INSTALL_MAN} ${WRKSRC}/src/ftpwho.1 ${PREFIX}/man/man1/ftpwho.1
	@${INSTALL_MAN} ${WRKSRC}/src/xferlog.5 ${PREFIX}/man/man5/xferlog.5
	@${INSTALL_MAN} ${WRKSRC}/src/ftpshut.8 ${PREFIX}/man/man8/ftpshut.8
	@${INSTALL_MAN} ${WRKSRC}/src/proftpd.8 ${PREFIX}/man/man8/proftpd.8
	@${INSTALL_DATA} \
		${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf.default
	@if [ ! -f ${PREFIX}/etc/proftpd.conf ]; then \
		${INSTALL_DATA} \
		${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf; \
	fi
	@${SED} -e 's,/usr/local,${PREFIX},g' ${FILESDIR}/proftpd.sh.sample > ${PREFIX}/etc/rc.d/proftpd.sh.sample

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
