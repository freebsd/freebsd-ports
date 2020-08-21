# Created by: Motoyuki Kasahara <m-kasahr@sra.co.jp>
# $FreeBSD$

PORTNAME=	ebnetd
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/

MAINTAINER=	yasu@utahime.org
COMMENT=	Servers for accessing CD-ROM books via TCP/IP

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeb.so:japanese/eb

USES=		iconv:patch
USE_RC_SUBR=	ebhttpd ebnetd ndtpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR}
CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl

SUB_FILES=	pkg-message

USERS=		${EBNETD_USER}
GROUPS=		${EBNETD_GROUP}

INFO=		ebnetd ebnetd-ja
PLIST_SUB=	EBNETD_RUNDIR=${RUNDIR}/${PORTNAME} \
		EBNETD_USER=${EBNETD_USER} \
		EBNETD_GROUP=${EBNETD_GROUP}

# Local variables
EBNETD_GROUP=	ebnetd
EBNETD_USER=	ebnetd
LOGDIR=		/var/log
RUNDIR=		/var/run

post-patch:
	${MV} ${WRKSRC}/doc-ja/ebnetd-ja.texi ${WRKSRC}/doc-ja/ebnetd-ja.texi.orig
	${ICONV_CMD} -f EUC-JP -t UTF-8 ${WRKSRC}/doc-ja/ebnetd-ja.texi.orig > ${WRKSRC}/doc-ja/ebnetd-ja.texi
	${REINPLACE_CMD} -e "s/%%EBNETD_USER%%/${EBNETD_USER}/" \
		-e "s/%%EBNETD_GROUP%%/${EBNETD_GROUP}/" \
		${WRKSRC}/ebnetd.conf.sample.in

post-install:
	${MKDIR} -m 0755 ${STAGEDIR}${RUNDIR}/${PORTNAME}

.include <bsd.port.mk>
