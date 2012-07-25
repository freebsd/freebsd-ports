# New ports collection makefile for:	vizone
# Date created:				13 Aug 2007
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vizone
PORTVERSION=	0.1
CATEGORIES=	dns
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Updates the serial number in one or more zonefiles

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTEXAMPLES=	example.tld
PLIST_FILES=	bin/vizone bin/updserial

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL}|' ${WRKSRC}/updserial

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/updserial ${PREFIX}/bin

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.tld ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
