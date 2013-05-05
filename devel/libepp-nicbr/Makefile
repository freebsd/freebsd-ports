# Created by: Jean Milanez Melo <jmelo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libepp-nicbr
PORTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.registro.br/pub/libepp-nicbr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partial Extensible Provisioning Protocol to .br domains

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	xerces-c:${PORTSDIR}/textproc/xerces-c3

OPTIONS_DEFINE=	READLINE
OPTIONS_DEFAULT=READLINE
READLINE_DESC=	Enable readline support

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_cppunit_TestRunner_h=no
CONFIGURE_ARGS=	--with-xerces-c=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}
MAKE_JOBS_SAFE=	yes

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

DATADIR=	${PREFIX}/share/${PORTNAME:S/-/_/}

PLIST_SUB=	VER="${PORTVERSION}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USE_READLINE=	yes
PLIST_SUB+=	READLINE=""
.else
CONFIGURE_ENV+=	ac_cv_lib_readline_readline=no
PLIST_SUB+=	READLINE="@comment "
.endif

.include <bsd.port.mk>
