PORTNAME=	libmodbus
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.11
CATEGORIES=	comms

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modbus library
WWW=		https://libmodbus.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		autoreconf cpe gmake libtool pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	stephane
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	go-md2man:textproc/go-md2man

post-install-MANPAGES-on:
	go-md2man -in docs/index.md | ${GZIP_CMD} > ${STAGEDIR}${PREFIX}/share/man/man7/libmodbus.7.gz
	for files in `${FIND} ${WRKSRC}/docs -type f -name 'modbus*.md'`; do \
		basefiles=`basename $${files} .md`; \
		go-md2man -in $${files} | ${GZIP_CMD} > ${STAGEDIR}${PREFIX}/share/man/man3/$${basefiles}.3.gz; \
	done

.include <bsd.port.mk>
