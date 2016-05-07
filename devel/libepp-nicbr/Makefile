# Created by: Jean Milanez Melo <jmelo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libepp-nicbr
PORTVERSION=	1.15
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.registro.br/pub/libepp-nicbr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partial Extensible Provisioning Protocol to .br domains

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_cppunit_TestRunner_h=no
CONFIGURE_ARGS=	--with-xerces-c=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}

DATADIR=	${PREFIX}/share/${PORTNAME:S/-/_/}

PLIST_SUB=	VER="${PORTVERSION}"

OPTIONS_DEFINE=		READLINE
OPTIONS_DEFAULT=	READLINE
OPTIONS_SUB=		yes

READLINE_USES=		ncurses readline
READLINE_CONFIGURE_ENV_OFF=\
			ac_cv_lib_readline_readline=no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE} && !exists(/usr/lib/libreadline.so)
CONFIGURE_ARGS+=--with-readline-includes=${LOCALBASE}/include
.endif

.include <bsd.port.mk>
