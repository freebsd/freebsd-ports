# New ports collection makefile for: vsftpd
# Date created:		03 Feb 2001
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vsftpd
PORTVERSION=	1.1.3
CATEGORIES=	ftp
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/

MAINTAINER=	dinoex@FreeBSD.org

USE_PERL5=	yes
ALL_TARGET=	vsftpd
MAN5=		vsftpd.conf.5
MAN8=		vsftpd.8
DOCFILES=	AUDIT BENCHMARKS BUGS COPYING Changelog FAQ INSTALL LICENSE \
		README README.security REWARD SIZE SPEED TODO TUNING

.include <bsd.port.pre.mk>

do-configure:
	@${MV} ${WRKSRC}/defs.h ${WRKSRC}/defs.h.sed
	${SED} -e "s=/etc/vsftpd.conf=${PREFIX}/etc/vsftpd.conf=" \
		${WRKSRC}/defs.h.sed > ${WRKSRC}/defs.h
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.sed
	${SED} -e "s/^CFLAGS	=/CFLAGS	+=/" \
		${WRKSRC}/Makefile.sed > ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/builddefs.h ${WRKSRC}/builddefs.h.sed
	${SED} -e "s/#undef VSF_BUILD_TCPWRAPPERS/#define VSF_BUILD_TCPWRAPPERS 1/" \
		${WRKSRC}/builddefs.h.sed > ${WRKSRC}/builddefs.h
	${SED} -e "s/^CFLAGS	=/CFLAGS	+=/" \
		${WRKSRC}/Makefile.sed > ${WRKSRC}/Makefile
	${ECHO_CMD} "secure_chroot_dir=${PREFIX}/share/vsftpd/empty" >> \
		${WRKSRC}/vsftpd.conf

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
	${PERL5} ${PKGINSTALL}
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
