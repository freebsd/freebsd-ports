# New ports collection makefile for:	irssi
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	0.7.98.3
CATEGORIES=	irc ipv6
MASTER_SITES=	http://irssi.org/files/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-socks --with-bot --without-servertest \
		--enable-perl-path=${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

CONFIGURE_ENV= LIBS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

pre-configure:
	@cd ${WRKSRC} && ${MV} config config.sample

post-install:
	@if [ ! -f ${LOCALBASE}/etc/irssi/config ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_SCRIPT} -m 644 ${WRKSRC}/config.sample ${LOCALBASE}/etc/irssi/config; \
	fi

.include <bsd.port.post.mk>
