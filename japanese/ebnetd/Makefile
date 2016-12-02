# Created by: Motoyuki Kasahara <m-kasahr@sra.co.jp>
# $FreeBSD$

PORTNAME=	ebnetd
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	japanese ipv6
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/

MAINTAINER=	yasu@utahime.org
COMMENT=	Servers for accessing CD-ROM books via TCP/IP

LICENSE=	GPLv2

LIB_DEPENDS=	libeb.so:japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR}
CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl

USERS=		${EBNETD_USER}
GROUPS=		${EBNETD_GROUP}

# Local variables
LOGDIR=		/var/log
RUNDIR=		/var/run
EBNETD_USER=	ebnetd
EBNETD_GROUP=	ebnetd

USE_RC_SUBR=	ebhttpd ebnetd ndtpd
SUB_FILES=	pkg-message
PLIST_SUB=	EBNETD_RUNDIR=${RUNDIR}/${PORTNAME} \
		EBNETD_USER=${EBNETD_USER} \
		EBNETD_GROUP=${EBNETD_GROUP}

INFO=		ebnetd ebnetd-ja

post-patch:
	${REINPLACE_CMD} -e "s/%%EBNETD_USER%%/${EBNETD_USER}/" \
		-e "s/%%EBNETD_GROUP%%/${EBNETD_GROUP}/" \
		${WRKSRC}/ebnetd.conf.sample.in

post-install:
	${MKDIR} -m 0755 ${STAGEDIR}${RUNDIR}/${PORTNAME}

.include <bsd.port.mk>
