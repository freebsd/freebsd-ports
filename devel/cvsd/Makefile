# ex:ts=8
# Ports collection makefile for:	cvsd
# Date Created:			Dec 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsd
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS pserver daemon

USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.sig
USE_PERL5=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-libwrap
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN5=	cvsd.conf.5
MAN8=	cvsd.8 cvsd-buildroot.8 cvsd-passwd.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsd ${PREFIX}/sbin/cvsd
.for FILE in cvsd-buildroot cvsd-passwd
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/cvsd.init ${PREFIX}/etc/rc.d/cvsd.sh.sample
	@${MKDIR} ${PREFIX}/etc/cvsd
	${INSTALL_DATA} ${WRKSRC}/cvsd.conf-dist ${PREFIX}/etc/cvsd/cvsd.conf.sample
.for FILE in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MAN5PREFIX}/man/man5
.endfor
.for FILE in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MAN8PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
