# Ports collection makefile for:	tftp-hpa
# Date created:				Tue Jan 14, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tftp-hpa
PORTVERSION=	0.49
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	software/network/tftp

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	An advanced tftp server

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/tftp \
		libexec/in.tftpd
.ifndef (NOPORTDOCS)
PORTDOCS=	CHANGES \
		README \
		README.security
.endif

MAN1=		tftp.1
MAN8=		in.tftpd.8
MLINKS=		in.tftpd.8 tftpd.8

post-patch:
	@${REINPLACE_CMD} -e 's,SBINDIR,LIBEXECDIR,; s,sbindir,libexecdir,' \
	    ${WRKSRC}/MCONFIG.in
	@${REINPLACE_CMD} -e 's,SBINDIR,LIBEXECDIR,g' \
	    ${WRKSRC}/tftpd/Makefile
	@${REINPLACE_CMD} -e 's,LOG_DAEMON,LOG_FTP,g' \
	    ${WRKSRC}/tftpd/tftpd.c

.ifdef PORTDOCS
post-install:
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
