# New ports collection makefile for:	libircclient
# Date created:				2008-11-20
# Whom:					Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libircclient
PORTVERSION=	1.3
CATEGORIES=	irc devel
MASTER_SITES=	SF

MAINTAINER=	kimelto@gmail.com
COMMENT=	An IRC library to create IRC clients

GNU_CONFIGURE=	yes

do-build:
	@${MAKE} -C ${WRKSRC}/src/

do-install:
	@${INSTALL_DATA} ${WRKSRC}/include/libircclient.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_errors.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_events.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_options.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_rfcnumeric.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/src/libircclient.a ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing additional examples to ${EXAMPLESDIR}"
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
