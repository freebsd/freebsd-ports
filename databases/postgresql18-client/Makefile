PORTNAME=	postgresql
PORTREVISION=	0

COMMENT=	PostgreSQL database (client)

MASTERDIR=	${.CURDIR}/../postgresql18-server

BUILD_DIRS=	config src/include src/interfaces src/port src/fe_utils src/bin/pg_amcheck \
		src/bin/pg_dump src/bin/psql src/bin/scripts src/bin/pg_config \
		src/bin/pgbench src/makefiles src/test/regress
INSTALL_DIRS=	${BUILD_DIRS}

CLIENT_ONLY=	yes
COMPONENT=	-client
USE_LDCONFIG=	yes
USES=		pkgconfig

OPTIONS_DEFINE+=LIBEDIT DOCS
LIBEDIT_DESC=	Use non-GPL libedit instead of readline
LIBEDIT_CONFIGURE_ON+=--with-libedit-preferred
LIBEDIT_USES=	libedit
LIBEDIT_USES_OFF=readline
BUILD_DEPENDS+=	docbook-xml>0:textproc/docbook-xml \
		docbook-xsl>=0:textproc/docbook-xsl \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt

.include "${MASTERDIR}/Makefile"
