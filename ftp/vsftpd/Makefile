# New ports collection makefile for: vsftpd
# Date created:		03 Feb 2001
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vsftpd
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A FTP daemon that aims to be "very secure"

USE_REINPLACE=	yes
ALL_TARGET=	vsftpd
MAN5=		vsftpd.conf.5
MAN8=		vsftpd.8
DOCFILES=	AUDIT BENCHMARKS BUGS Changelog FAQ INSTALL LICENSE \
		README README.security REWARD SIZE SPEED TODO TUNING

.include <bsd.port.pre.mk>

do-configure:
	${REINPLACE_CMD} -e "s=/etc/vsftpd.conf=${PREFIX}/etc/vsftpd.conf=" \
		${WRKSRC}/defs.h
	${REINPLACE_CMD} -e "s/^CFLAGS	=/CFLAGS	+=/" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		"s/#undef VSF_BUILD_TCPWRAPPERS/#define VSF_BUILD_TCPWRAPPERS 1/" \
		${WRKSRC}/builddefs.h
	${ECHO_CMD} "secure_chroot_dir=${PREFIX}/share/vsftpd/empty" >> \
		${WRKSRC}/vsftpd.conf
	${REINPLACE_CMD} -e "s=/etc/v=${PREFIX}/etc/v=" \
		${WRKSRC}/vsftpd.8 ${WRKSRC}/vsftpd.conf.5 ${WRKSRC}/tunables.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${PREFIX}/libexec/
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${PREFIX}/etc/vsftpd.conf.dist
	${INSTALL} -d ${PREFIX}/share/vsftpd/empty
	@if [ ! -e ${PREFIX}/etc/vsftpd.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${PREFIX}/etc/ ; \
	fi
	${MKDIR} ${PREFIX}/share/vsftpd/empty
	@for i in ${MAN8} ; do \
		${INSTALL_MAN} -m 644 ${WRKSRC}/$${i} ${MANPREFIX}/man/man8/ ; \
		done
	@for i in ${MAN5} ; do \
		${INSTALL_MAN} -m 644 ${WRKSRC}/$${i} ${MANPREFIX}/man/man5/ ; \
		done
	${SH} ${PKGINSTALL}
	${MKDIR} /var/ftp
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} -m 644 ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in EXAMPLE SECURITY
	${MKDIR} ${DOCSDIR}/${i}
	${CP} -p -R -L ${WRKSRC}/${i}/./ ${DOCSDIR}/${i}/
	${CHMOD} -R -L a+rX,go-w ${DOCSDIR}/${i}/
.endfor
.endif

.include <bsd.port.post.mk>
