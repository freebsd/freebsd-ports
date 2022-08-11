PORTNAME=	dsc
PORTVERSION=	2.13.0
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/dsc/ \
		https://dns.company/files/dsc/

MAINTAINER=	freebsd@dns.company
COMMENT=	Tool used for collecting and exploring statistics from DNS servers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
RUN_DEPENDS=	libpcap>=1.8.1:net/libpcap \
		p5-Proc-PID-File>=1.28:devel/p5-Proc-PID-File \
		p5-XML-Simple>=2.24:textproc/p5-XML-Simple

USES=		gmake localbase perl5 python:3.6+ shebangfix
USE_RC_SUBR=	dsc
SHEBANG_FILES=	src/dsc-psl-convert

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-extract:
	${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' \
	    ${WRKSRC}/src/dsc.conf.5.in \
	    ${WRKSRC}/src/dsc.sh

post-install:
	${MKDIR} ${STAGEDIR}/var/lib/${PORTNAME}

.include <bsd.port.mk>
