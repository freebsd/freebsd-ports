# New ports collection makefile for:   pcsc-lite
# Date created:                15 Oct 2001
# Whom:                        Toni Andjelkovic <toni@ants.at>
#
# $FreeBSD$
#

PORTNAME=	pcsc-lite
PORTVERSION=	1.0.2.b2
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/middleware/files/
DISTNAME=	pcsc-lite-${PORTVERSION:S/b/beta/}

MAINTAINER=	toni@ants.at

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES+=	build/aclocal.m4

INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--enable-syslog --enable-daemon \
			--enable-runpid=/var/run/pcscd.pid
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${PERL} -pi -e 's,SUBDIRS = src etc doc,SUBDIRS = src,' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.DAEMON ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pcsc-lite-0.8.7.pdf ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf \
		${PREFIX}/etc/reader.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pcscd.sh \
		${PREFIX}/etc/rc.d/pcscd.sh.sample
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
