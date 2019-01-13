# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	dsc
PORTVERSION=	2.7.0
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/dsc/ \
		https://dns.company/files/dsc/

MAINTAINER=	freebsd@dns.company
COMMENT=	Tool used for collecting and exploring statistics from DNS servers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	libpcap>=1.8.1:net/libpcap			\
		GeoIP>=1.6.12:net/GeoIP				\
		p5-Proc-PID-File>=1.28:devel/p5-Proc-PID-File	\
		p5-XML-Simple>=2.24:textproc/p5-XML-Simple	\
		dsp>=2.0.0:dns/dsp

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-cflags=-I${LOCALBASE}/include
USES=		gmake perl5 shebangfix

SUB_FILES=	pkg-message

USE_RC_SUBR=    dsc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
