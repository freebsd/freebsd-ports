# New ports collection makefile for:	njs
# Date created:		Fri Jan 11 20:45:26 GMT 2002
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	njs
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.njs-javascript.org/	\
		http://people.ssh.fi/mtr/js/	\
		http://www.bbassett.net/njs/	\
		http://www.iki.fi/mtr/js/
DISTNAME=	js-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NJS (NGS) is a standalone JavaScript/ECMAScript interpreter

CONFLICTS=	js-1.5.*

USE_INC_LIBTOOL_VER=13
.if defined(NOPORTDOCS)
USE_REINPLACE=	yes
.endif
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=	js.1 jsdas.1
INFO=	js

post-extract:
	@${RM} ${WRKSRC}/docs/js.info*

pre-install:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s:docs micros examples:micros:g" ${WRKSRC}/Makefile
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
