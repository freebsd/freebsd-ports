# New ports collection makefile for: vsftpd
# Date created:		03 Feb 2001
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vsftpd
PORTVERSION=	1.1.2
CATEGORIES=	ftp
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/

MAINTAINER=	dinoex@FreeBSD.org

USE_PERL5=	yes
ALL_TARGET=	vsftpd

MAN5=		vsftpd.conf.5

MAN8=		vsftpd.8

.include <bsd.port.pre.mk>

post-patch:
	@${MV} ${WRKSRC}/defs.h ${WRKSRC}/defs.h.sed
	${SED} -e "s=/etc/vsftpd.conf=${PREFIX}/etc/vsftpd.conf=" \
		${WRKSRC}/defs.h.sed > ${WRKSRC}/defs.h
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.sed
	${SED} -e "s/^CFLAGS	=/CFLAGS	+=/" \
		${WRKSRC}/Makefile.sed > ${WRKSRC}/Makefile
	@${ECHO_CMD} "secure_chroot_dir=${PREFIX}/share/vsftpd/empty" >> \
		${WRKSRC}/vsftpd.conf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${PREFIX}/libexec/
	@${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${PREFIX}/etc/vsftpd.conf.dist
	@${INSTALL} -d ${PREFIX}/share/vsftpd/empty
	@if [ ! -e ${PREFIX}/etc/vsftpd.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${PREFIX}/etc/ ; \
	fi
	@${MKDIR} ${PREFIX}/share/vsftpd/empty
	@for i in ${MAN8} ; do \
		${INSTALL_MAN} -m 644 ${WRKSRC}/$${i} ${MANPREFIX}/man/man8/ ; \
		done
	@for i in ${MAN5} ; do \
		${INSTALL_MAN} -m 644 ${WRKSRC}/$${i} ${MANPREFIX}/man/man5/ ; \
		done
	@${PERL5} ${PKGINSTALL}
	@${MKDIR} /var/ftp

.include <bsd.port.post.mk>
