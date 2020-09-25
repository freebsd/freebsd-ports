# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The contrib utilities from the PostgreSQL distribution

MASTERDIR=	${.CURDIR}/../postgresql12-server

USES=		bison pgsql:${DISTVERSION:C/([0-9]\.?[0-9]).*/\1/g}

BUILD_DIRS=	src/port src/include src/common contrib
INSTALL_DIRS=	contrib

SLAVE_ONLY=	yes
COMPONENT=	-contrib
CONFIGURE_ARGS=	--disable-nls --with-uuid=bsd
LDFLAGS+=	-lpthread -L${PREFIX}/lib

OPTIONS_DEFINE=	DOCS OPENSSL XML
OPTIONS_DEFAULT=OPENSSL XML
OPTIONS_SUB=	yes

OPENSSL_DESC=		Build with OpenSSL support
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl

XML_CONFIGURE_WITH=	libxslt libxml
XML_LIB_DEPENDS=libxslt.so:textproc/libxslt \
		libxml2.so:textproc/libxml2

post-configure:
	@cd ${WRKSRC}/src/backend && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} symlinks

post-install:
	@- ${INSTALL_DATA} ${WRKSRC}/contrib/README ${STAGEDIR}${DOCSDIR}/extension/README

.include "${MASTERDIR}/Makefile"
