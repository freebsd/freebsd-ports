# New ports collection makefile for:	byacc
# Date created:				28 Jun 2002
# Whom:					David Xu
#
# $FreeBSD$
#

PORTNAME=	byaccj
PORTVERSION=	1.1
CATEGORIES=	devel java
MASTER_SITES=	http://troi.lincom-asg.com/~rjamison/byacc/ \
		http://opensource.zjonline.com.cn/distfiles/
DISTNAME=	byaccj1.1

MAINTAINER=	davidxu@viatech.com.cn
COMMENT=	A java extension of BSD YACC-compatible parser generator

PLIST_FILES=	bin/byaccj
WRKSRC=		$(WRKDIR)/byaccj1.1/src
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#<malloc.h>#<stdlib.h>#' ${WRKSRC}/defs.h ${WRKSRC}/*c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yacc ${PREFIX}/bin/byaccj

.include <bsd.port.mk>
