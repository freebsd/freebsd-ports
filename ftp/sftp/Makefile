# New ports collection makefile for:	sftp
# Version required:	0.5
# Date created:		30 December 1999
# Whom:			Cy Shubert <Cy.Shubert@uumail.gov.bc.ca>
#
# $FreeBSD$
#

DISTNAME=	sftp-0.5
CATEGORIES=	ftp security
MASTER_SITES=	ftp://ftp.xbill.org/pub/sftp/

MAINTAINER=	Cy.Schubert@uumail.gov.bc.ca

RUN_DEPENDS=	ssh:${PORTSDIR}/security/openssh

RESTRICTED=	"Calls external cryptographic routines."

GNU_CONFIGURE=  yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--enable-remotepath=${PREFIX}/libexec

MAN1=		sftp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sftp ${PREFIX}/bin/sftp
	${LN} -s ${PREFIX}/bin/sftp ${PREFIX}/bin/rsftp
	${INSTALL_PROGRAM} ${WRKSRC}/sftpserv ${PREFIX}/libexec/sftpserv
	${INSTALL_MAN} ${WRKSRC}/sftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
