# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vizone
PORTVERSION=	0.1
CATEGORIES=	dns
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Updates the serial number in one or more zonefiles

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes

SHEBANG_FILES=	updserial

PORTEXAMPLES=	example.tld
PLIST_FILES=	bin/vizone bin/updserial

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/updserial ${STAGEDIR}${PREFIX}/bin

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.tld ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
