PORTNAME=	bbftp-server
PORTVERSION=	3.2.1
CATEGORIES=	ftp
MASTER_SITES=	http://software.in2p3.fr/bbftp/dist/ \
		ftp://ftp.in2p3.fr/pub/bbftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure file transfer suite optimized for large files (server)

LICENSE=	GPLv2+

USES=		gmake ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
WRKSRC_SUBDIR=	bbftpd
USE_RC_SUBR=	bbftpd

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^#include/s,malloc,stdlib,' \
		${WRKSRC}/bbftpd_cd.c ${WRKSRC}/bbftpd_statfs.c
	@${REINPLACE_CMD} -e '/with_ssl\/lib\/libcrypto/s,\.a,.so,' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbftpd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/bbftpd.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/ports ${WRKSRC}/../doc/stats \
		${WRKSRC}/../ChangeLog ${WRKSRC}/../README \
		${WRKSRC}/../TODO ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
