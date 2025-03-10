PORTNAME=	libepp-nicbr
DISTVERSION=	1.20
CATEGORIES=	devel
MASTER_SITES=	https://ftp.registro.br/pub/libepp-nicbr/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Partial Extensible Provisioning Protocol to .br domains
WWW=		https://registro.br/epp/ \
		https://registro.br/epp/rfc-EN.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		libtool pkgconfig ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xerces-c=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--with-readline-includes=${LOCALBASE}/include
CONFIGURE_ENV=	ac_cv_header_cppunit_TestRunner_h=no

DATADIR=	${PREFIX}/share/${PORTNAME:S/-/_/}

PLIST_SUB=	VER="${PORTVERSION}"

OPTIONS_DEFINE=		READLINE
OPTIONS_DEFAULT=	READLINE
OPTIONS_SUB=		yes

READLINE_USES=		ncurses readline
READLINE_CONFIGURE_ENV_OFF=\
			ac_cv_lib_readline_readline=no

.include <bsd.port.mk>
