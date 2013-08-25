# $FreeBSD$

PORTNAME=	ebnetd
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	japanese ipv6
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/

MAINTAINER=	yasu@utahime.org
COMMENT=	Servers for accessing CD-ROM books via TCP/IP

LICENSE=	GPLv2

LIB_DEPENDS=	eb:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR}

# Local variables
LOGDIR=		/var/log
RUNDIR=		/var/run

USE_RC_SUBR=	ebhttpd ebnetd ndtpd
SUB_FILES=	pkg-message
PLIST_SUB=	EBNETD_RUNDIR=${RUNDIR}/${PORTNAME}

INFO=		ebnetd ebnetd-ja

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
