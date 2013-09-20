# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	bbftp
PORTVERSION=	3.0.2
CATEGORIES=	ftp
MASTER_SITES=	http://doc.in2p3.fr/bbftp/dist/ \
		http://ftp.riken.go.jp/pub/net/bbftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple stream file transfer protocol optimized for large files

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EXTRA_PATCHES=	${FILESDIR}/bbftp.patch

USE_RC_SUBR=	bbftpd

MAN1=		bbftp.1 bbftpd.1

NO_STAGE=	yes
do-configure:
	${CP} -f ${TEMPLATES}/config.guess ${WRKSRC}
	${CP} -f ${TEMPLATES}/config.sub ${WRKSRC}
	cd ${WRKSRC}/bbftpc && ./configure --prefix=${PREFIX} ${CONFIGURE_ARGS}
	cd ${WRKSRC}/bbftpd && ./configure --prefix=${PREFIX} ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/bbftpc && ${GMAKE}
	cd ${WRKSRC}/bbftpd && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbftpc/bbftp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bbftpd/bbftpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bbftp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bbftpd.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
