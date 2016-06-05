# Created by: Garrett Wollman <wollman@lcs.mit.edu>
# $FreeBSD$

PORTNAME=	uclmmbase
PORTVERSION=	1.2.18
CATEGORIES=	devel ipv6
MASTER_SITES=	http://aldan.algebra.com/~mi/port-stuff/
DISTNAME=	common-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Common subroutines for UCL mbone applications

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
OPTIONS_DEFINE=	IPV6

WRKSRC=		${WRKDIR}/common
USES=		uidfix tar:xz
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
IPV6_CONFIGURE_ENABLE=	ipv6
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null
INSTALL_WRKSRC=	${WRKSRC}/src

post-configure:
	@for f in ${FILESDIR}/*.bsd ; do \
		${LN} -sf $$f ${WRKSRC}/src/`${BASENAME} $$f .bsd` ; \
	done

# Run the test, and fail if we hit an error. Don't fail in case of
# the networking-error, which may be due IPv6 (or IPv4) being unavailable
# or some network (mis)configuration:
post-build test:
	cd ${WRKSRC} && tests/test-libcommon 2>&1 | ${AWK} '	\
		/fail$$/ && $$2 != "networking" { code=1 }	\
		{ print } END { exit code }'

.include <bsd.port.mk>
