# New ports collection makefile for:	adabooch
# Date created:			21 December 2002
# Whom:				David Holm <david@realityrift.com>
#
# $FreeBSD$
#

PORTNAME=	adabooch
PORTVERSION=	20030309
CATEGORIES=	devel
MASTER_SITES=	http://www.adapower.net/booch/download/
DISTNAME=	bc-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Library which provide container classes as well as powertools for Ada

NO_BUILD=	yes

do-install:
	@${ECHO} Installing library files
	@${MKDIR} ${PREFIX}/lib/adabooch
	@for i in `cat pkg-plist|grep "lib/adabooch/"|sed "s/lib\/adabooch\///"`; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/lib/adabooch; \
	done

	@${MKDIR} ${PREFIX}/share/adabooch
	@${ECHO} Installing demos and tests
	@${MKDIR} ${PREFIX}/share/adabooch/demo
	@for i in `cat pkg-plist|grep "share/adabooch/demo/"|sed "s/share\/adabooch\/demo\///"`; do \
		${INSTALL_DATA} ${WRKSRC}/demo/$${i} ${PREFIX}/share/adabooch/demo; \
	done

	@${MKDIR} ${PREFIX}/share/adabooch/test
	@for i in `cat pkg-plist|grep "share/adabooch/test/"|sed "s/share\/adabooch\/test\///"`; do \
		${INSTALL_DATA} ${WRKSRC}/test/$${i} ${PREFIX}/share/adabooch/test; \
	done

post-install:
	@${ECHO}
	@${ECHO} "The booch library has been installed into ${PREFIX}/lib/adabooch"
	@${ECHO}

.include <bsd.port.mk>
