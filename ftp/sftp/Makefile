# New ports collection makefile for:	sftp
# Date created:		30 December 1999
# Whom:			Cy Shubert <Cy.Shubert@uumail.gov.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	sftp
PORTVERSION=	0.9.9
CATEGORIES=	ftp security
MASTER_SITES=	ftp://ftp.xbill.org/pub/sftp/old/ \
		http://www.komquats.com/distfiles/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	An ftp replacement that runs over an ssh tunnel

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400014
RUN_DEPENDS=	ssh:${PORTSDIR}/security/openssh
.endif

GNU_CONFIGURE=	yes

MAN1=		secftp.1

PLIST=		${WRKDIR}/.PLIST

pre-install:
	@${CP} ${PKGDIR}/pkg-plist.in ${PLIST}.unsorted
	@if [ ! -f ${PREFIX}/bin/sftp ]; then \
		${ECHO_CMD} bin/sftp >> ${PLIST}.unsorted; \
		${ECHO_CMD} man/man1/sftp.1.gz >> ${PLIST}.unsorted; \
	fi
	@${SORT} -u ${PLIST}.unsorted > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sftp ${PREFIX}/bin/secftp
	${LN} -s ${PREFIX}/bin/secftp ${PREFIX}/bin/rsftp
	${INSTALL_PROGRAM} ${WRKSRC}/sftpserv ${PREFIX}/bin/sftpserv
	${INSTALL_MAN} ${WRKSRC}/sftp.1 ${PREFIX}/man/man1/secftp.1
	@if [ ! -f ${PREFIX}/bin/sftp ]; then \
		${ECHO} "No other sftp found, linking sftp to secftp"; \
		${LN} -s ${PREFIX}/bin/secftp ${PREFIX}/bin/sftp; \
		${LN} -s ${PREFIX}/man/man1/secftp.1.gz ${PREFIX}/man/man1/sftp.1.gz; \
	else \
		${ECHO} "Other sftp found, not linking sftp to secftp"; \
	fi

.include <bsd.port.post.mk>
