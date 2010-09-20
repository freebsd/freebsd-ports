# New ports collection makefile for:   mysqltuner
# Date created:		09 September 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysqltuner
PORTVERSION=	1.1.0
CATEGORIES=	databases
MASTER_SITES=	http://mysqltuner.pl/
DISTNAME=	${PORTNAME}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Script Assist You with MySQL Configuration

USE_PERL=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

pre-patch:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|"1.0.1";|"1.1.0";|' \
		${WRKSRC}/${DISTNAME}

.include <bsd.port.pre.mk>
do-install:
	@${CP} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${DISTNAME}
	@${CHMOD} 755 ${PREFIX}/bin/${DISTNAME}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/bin/${DISTNAME}.pl' \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
