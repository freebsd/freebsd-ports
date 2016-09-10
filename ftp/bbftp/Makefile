# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	bbftp
PORTVERSION=	3.0.2
CATEGORIES=	ftp
MASTER_SITES=	http://doc.in2p3.fr/bbftp/dist/ \
		http://ftp.riken.go.jp/pub/net/bbftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple stream file transfer protocol optimized for large files

USES=		gmake ssl:build
GNU_CONFIGURE=	yes

EXTRA_PATCHES=	${FILESDIR}/bbftp.patch

USE_RC_SUBR=	bbftpd

do-configure:
	${CP} -f ${TEMPLATES}/config.guess ${WRKSRC}
	${CP} -f ${TEMPLATES}/config.sub ${WRKSRC}
	(cd ${WRKSRC}/bbftpc && ./configure --prefix=${PREFIX} \
		${CONFIGURE_ARGS} --with-ssl=${OPENSSLBASE})
	(cd ${WRKSRC}/bbftpd && ./configure --prefix=${PREFIX} \
		${CONFIGURE_ARGS} --with-ssl=${OPENSSLBASE})

do-build:
	(cd ${WRKSRC}/bbftpc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})
	(cd ${WRKSRC}/bbftpd && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbftpc/bbftp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bbftpd/bbftpd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bbftp.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bbftpd.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
