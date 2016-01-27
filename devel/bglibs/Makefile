# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	bglibs
PORTVERSION=	1.106
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://untroubled.org/${PORTNAME}/archive/ \
		http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	One stop library package by Bruce Guenter

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool:build perl5
USE_PERL5=	run
BGLIBS_INC=	${PREFIX}/include/${PORTNAME}
BGLIBS_LIB=	${PREFIX}/lib/${PORTNAME}
USE_LDCONFIG=	${BGLIBS_LIB}

DOCS=		NEWS README TODO doc/html/*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/main/s/^void/int/' ${WRKSRC}/sys/try*.c

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${STAGEDIR}${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${STAGEDIR}${BGLIBS_INC}"	> ${WRKSRC}/conf-include
	${ECHO_CMD} "${STAGEDIR}${BGLIBS_LIB}"	> ${WRKSRC}/conf-lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/bglibs/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && ${SH} selftests.sh

.include <bsd.port.mk>
