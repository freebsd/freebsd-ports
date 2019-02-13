# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	dsc
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/dsc/ \
		https://dns.company/files/dsc/

MAINTAINER=	freebsd@dns.company
COMMENT=	Tool used for collecting and exploring statistics from DNS servers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	libpcap>=1.8.1:net/libpcap \
		p5-Proc-PID-File>=1.28:devel/p5-Proc-PID-File \
		p5-XML-Simple>=2.24:textproc/p5-XML-Simple \
		dsp>=2.0.0:dns/dsp
LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		gmake perl5 shebangfix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-cflags=-I${LOCALBASE}/include

SUB_FILES=	pkg-message

USE_RC_SUBR=    dsc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
