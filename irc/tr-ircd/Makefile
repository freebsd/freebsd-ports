# New ports collection makefile for:	tr-ircd
# Date created:         Sat May 4 15:54:47 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	tr-ircd
PORTVERSION=	5.0.p6
CATEGORIES=	irc ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/-//}-release-${PORTVERSION:S/.p/-pre/}

MAINTAINER=	sysadmin@alexdupre.com

MAN1=		md5sum.1
MAN5=		ircd.conf.5
MAN8=		ircd.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-kqueue

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--enable-openssl=${OPENSSLBASE}
.endif

.if defined(SMALL_NET)
CONFIGURE_ARGS+=--enable-small-nets
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=--enable-ipv6
.endif

post-patch:
	@${PERL} -pi -e 's|\[ "(`[^`]+`)" == "" \]|[ test \1 ]|g' \
		${WRKSRC}/*/Makefile.in

post-install:
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/tr-ircd.sh.sample startup file."
	@${INSTALL_SCRIPT} ${FILESDIR}/tr-ircd.sh \
		${PREFIX}/etc/rc.d/tr-ircd.sh.sample

.include <bsd.port.post.mk>
