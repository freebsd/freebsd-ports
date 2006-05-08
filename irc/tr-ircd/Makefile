# New ports collection makefile for:	tr-ircd
# Date created:         Sat May 4 15:54:47 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	tr-ircd
PORTVERSION=	5.1.7
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/-//}-release-${PORTVERSION}-r

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An irc daeemon based on Bahamut and hybrid-7

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--libdir=${PREFIX}/lib/tr-ircd \
		--includedir=${PREFIX}/include/tr-ircd \
		--enable-kqueue \
		--enable-root \
		--with-fakehost-postfix=COM

MAN1=		md5sum.1
MAN5=		ircd.conf.5
MAN8=		ircd.8

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--enable-openssl=${OPENSSLBASE}
.endif

.if defined(SMALL_NET)
CONFIGURE_ARGS+=--enable-small-nets
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4 # Needs va_copy
.endif

.if ${OSVERSION} >= 400014 && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-O2,${CFLAGS}," ${WRKSRC}/configure

post-install:
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/tr-ircd.sh.sample startup file."
	@${INSTALL_SCRIPT} ${FILESDIR}/tr-ircd.sh \
		${PREFIX}/etc/rc.d/tr-ircd.sh.sample

.include <bsd.port.post.mk>
