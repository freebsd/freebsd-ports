# New ports collection makefile for:	openal
# Date created:		25 September 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION= 	20000908
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.openal.org/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}/linux
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	for file in $$(find ${WRKSRC} -name Makefile.in); \
	do \
		perl -pi -e 's/-g -c/-c/g' $${file}; \
	done

.include <bsd.port.mk>
