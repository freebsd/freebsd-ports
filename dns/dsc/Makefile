# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	dsc
PORTVERSION=	2.8.0
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
		p5-XML-Simple>=2.24:textproc/p5-XML-Simple \
		dsp>=2.0.0:dns/dsp

USES=		gmake perl5 shebangfix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-cflags=-I${LOCALBASE}/include

SUB_FILES=	pkg-message
SHEBANG_FILES=	cron/upload-prep.pl

USE_RC_SUBR=	dsc

OPTIONS_DEFINE=	DOCS

post-extract:
	${REINPLACE_CMD} -e 's|/usr/local/dsc/etc|${PREFIX}/etc/dsc|' \
	    ${WRKSRC}/cron/upload-prep.pl
	${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' \
	    ${WRKSRC}/cron/upload-rsync.sh \
	    ${WRKSRC}/cron/upload-ssh.sh \
	    ${WRKSRC}/cron/upload-x509.sh \
	    ${WRKSRC}/src/dsc.conf.5.in \
	    ${WRKSRC}/src/dsc.sh

.include <bsd.port.mk>
