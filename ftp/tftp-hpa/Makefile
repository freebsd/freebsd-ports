# $FreeBSD$

PORTNAME=	tftp-hpa
PORTVERSION=	5.2
CATEGORIES=	ftp
MASTER_SITES=	KERNEL_ORG/software/network/tftp/tftp-hpa

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Advanced TFTP server

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		gmake tar:xz
USE_RC_SUBR=	tftpd

DESTDIRNAME=	INSTALLROOT

PLIST_FILES=	bin/tftp \
		libexec/in.tftpd \
		man/man1/tftp.1.gz \
		man/man8/in.tftpd.8.gz \
		man/man8/tftpd.8.gz
PORTDOCS=	CHANGES \
		README \
		README.security

post-patch:
	@${REINPLACE_CMD} -e 's,SBINDIR,LIBEXECDIR,; s,sbindir,libexecdir,' \
	    ${WRKSRC}/MCONFIG.in
	@${REINPLACE_CMD} -e 's,SBINDIR,LIBEXECDIR,g' \
	    ${WRKSRC}/tftpd/Makefile
	@${REINPLACE_CMD} -e 's,LOG_DAEMON,LOG_FTP,g' \
	    -e 's,openlog(,tzset();openlog(,g' \
	    ${WRKSRC}/tftpd/tftpd.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
