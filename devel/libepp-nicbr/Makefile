# Created by: Jean Milanez Melo <jmelo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libepp-nicbr
PORTVERSION=	1.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.registro.br/pub/libepp-nicbr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partial Extensible Provisioning Protocol to .br domains

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so:${PORTSDIR}/textproc/xerces-c3

OPTIONS_DEFINE=	READLINE
OPTIONS_DEFAULT=READLINE
OPTIONS_SUB=	yes
READLINE_DESC=	Enable readline support

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_cppunit_TestRunner_h=no
CONFIGURE_ARGS=	--with-xerces-c=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}

DATADIR=	${PREFIX}/share/${PORTNAME:S/-/_/}

PLIST_SUB=	VER="${PORTVERSION}"

USES=		gmake

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
.  if !exists(/usr/lib/libreadline.so)
CONFIGURE_ARGS+=--with-readline-includes=${LOCALBASE}/include
.  endif
.else
CONFIGURE_ENV+=	ac_cv_lib_readline_readline=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|ncurses|curses|g' ${WRKSRC}/configure

.include <bsd.port.mk>
