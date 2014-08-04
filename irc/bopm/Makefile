# Created by: Evgueni V. Gavrilov <aquatique@rusunix.org>
# $FreeBSD$

PORTNAME=	bopm
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://static.blitzed.org/www.blitzed.org/bopm/files/ \
		ftp://rusunix.org/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open proxy and DNSBL monitor designed for use with ircds

LOGDIR=		/var/log/${PORTNAME}

USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure src/libopm/configure
CONFIGURE_ARGS=		--sysconfdir=${PREFIX}/etc --localstatedir=${LOGDIR}

USE_LDCONFIG=	yes
USE_RC_SUBR=	bopm

SUB_FILES=	pkg-message pkg-deinstall
PLIST_SUB=	LOGDIR=${LOGDIR}
SUB_LIST=	LOGDIR=${LOGDIR}

USERS=	bopm
GROUPS=	bopm

post-patch:
	@${REINPLACE_CMD} \
		-e 's,data_DATA = bopm.conf.sample,data_DATA =,g' \
		-e 's,$$(sysconfdir)/bopm.conf,$$(DESTDIR)&.sample,g' \
		-e '/localstatedir/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e 's,/some/path/bopm.pid,${LOGDIR}/bopm.pid,g' \
		-e 's,/some/path/scan.log,${LOGDIR}/scan.log,g' \
		${WRKSRC}/bopm.conf.sample

.include <bsd.port.mk>
