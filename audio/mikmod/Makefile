# New ports collection makefile for:	mikmod
# Version required:	3.0.3
# Date created:		20 April 1997
# Whom:			doconnor@gsoft.com.au
#
# $Id: Makefile,v 1.4 1998/01/22 00:20:17 msmith Exp $
#

DISTNAME=	mikmod-3.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.freenet.tlh.fl.us/~amstpi/

MAINTAINER=	yoshiaki@kt.rim.or.jp

do-build:
	(cd $(WRKSRC); /bin/sh build-mikmod.freebsd.sh)

do-install:
	( cd ${WRKSRC}/usercode ; ${INSTALL_PROGRAM} mikmod ${PREFIX}/bin )
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mikmod
.for f in bugs.txt changes.txt future.txt mikmod.txt tips.txt
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/$f ${PREFIX}/share/doc/mikmod
.endfor
.endif

.include <bsd.port.mk>
