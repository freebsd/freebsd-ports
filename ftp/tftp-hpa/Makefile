# $FreeBSD$

PORTNAME=	tftp-hpa
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	KERNEL_ORG/software/network/tftp/tftp-hpa

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced TFTP server

LICENSE=	BSD4CLAUSE

USES=		gmake tar:xz
GNU_CONFIGURE=	yes
USE_RC_SUBR=	tftpd

OPTIONS_DEFINE=	DOCS

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

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
