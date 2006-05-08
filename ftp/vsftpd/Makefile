# New ports collection makefile for: vsftpd
# Date created:		03 Feb 2001
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vsftpd
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/
PKGNAMESUFFIX?=	${SSL_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A FTP daemon that aims to be "very secure"

ALL_TARGET=	vsftpd
MAN5=		vsftpd.conf.5
MAN8=		vsftpd.8
DOCFILES=	AUDIT BENCHMARKS BUGS Changelog FAQ INSTALL LICENSE \
		README README.security README.ssl REFS REWARD \
		SIZE SPEED TODO TUNING

LDFLAGS+=	-lwrap

OPTIONS=	RC_NG		"install RC_NG script"		off \
		VSFTPD_SSL	"Include support for SSL"	off

.include <bsd.port.pre.mk>

.if defined(WITH_RC_NG)
USE_RC_SUBR=	vsftpd.sh
.endif

.if defined(WITH_VSFTPD_SSL) && !defined(WITHOUT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
SSL_SUFFIX=	-ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.else
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
.endif

do-configure:
	${REINPLACE_CMD} -e "s=/etc/vsftpd.conf=${PREFIX}/etc/vsftpd.conf=" \
		${WRKSRC}/defs.h
	${REINPLACE_CMD} \
		-e "s|^CC 	=	gcc|CC	= ${CC}|" \
		-e "s|^CFLAGS	=|CFLAGS	= ${CFLAGS}|" \
		-e "s|	-Wl,-s| -Wl,-s ${LDFLAGS}|" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		"s/#undef VSF_BUILD_TCPWRAPPERS/#define VSF_BUILD_TCPWRAPPERS 1/" \
		${WRKSRC}/builddefs.h
	${ECHO_CMD} "secure_chroot_dir=${PREFIX}/share/vsftpd/empty" >> \
		${WRKSRC}/vsftpd.conf
	${REINPLACE_CMD} -e "s=/etc/v=${PREFIX}/etc/v=" \
		${WRKSRC}/vsftpd.8 ${WRKSRC}/vsftpd.conf.5 ${WRKSRC}/tunables.c
.if !defined(WITHOUT_SSL) && defined(WITH_VSFTPD_SSL)
	${REINPLACE_CMD} -e \
		"s/#undef VSF_BUILD_SSL/#define VSF_BUILD_SSL 1/" \
		${WRKSRC}/builddefs.h
.endif

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
