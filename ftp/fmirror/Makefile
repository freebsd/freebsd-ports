# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	fmirror
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.guardian.no/pub/free/ftp/fmirror/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/

MAINTAINER=	kiwi@oav.net
COMMENT=	Program for mirroring files and directories from a remote FTP server

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} fmirror ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_MAN} ${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	cd ${WRKSRC} && \
		${INSTALL_DATA} ChangeLog README ${STAGEDIR}${DOCSDIR} && \
	cd ${WRKSRC}/configs && \
		${INSTALL_DATA} generic.conf redhat.conf sample.conf \
			${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
