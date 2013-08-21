# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	bglibs
PORTVERSION=	1.106
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://untroubled.org/${PORTNAME}/archive/ \
		http://untroubled.org/${PORTNAME}/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	One stop library package by Bruce Guenter

LICENSE=	LGPL21

NOT_FOR_ARCHS=	alpha

USES=		perl5
USE_PERL5=	run
USE_AUTOTOOLS=	libtool:env
BGLIBS_INC=	${PREFIX}/include/${PORTNAME}
BGLIBS_LIB=	${PREFIX}/lib/${PORTNAME}
USE_LDCONFIG=	${BGLIBS_LIB}

DOCS=		NEWS README TODO doc/html/*
MAN1=		cli-generate.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} '/main/s/^void/int/' ${WRKSRC}/sys/try*.c

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${PREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-include
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-lib

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

selftest: build
	cd ${WRKSRC} && ${SH} selftests.sh

.include <bsd.port.mk>
