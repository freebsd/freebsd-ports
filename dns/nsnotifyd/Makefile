PORTNAME=	nsnotifyd
PORTVERSION=	2.0
CATEGORIES=	dns
MASTER_SITES=	http://dotat.at/prog/nsnotifyd/

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Handle DNS NOTIFY messages by running a command

LICENSE=	CC0-1.0

GNU_CONFIGURE=	yes

USES=		shebangfix
SHEBANG_FILES=	nsnotify-liststealth

USE_RC_SUBR=	nsnotifyd

EXEFILES=	nsnotify nsnotifyd
BINFILES=	nsnotify-liststealth nsnotify2git nsnotify2stealth nsnotify2update
MAN1FILES=	metazone nsnotify nsnotifyd
MAN5FILES=	metazone

do-install:
.for bin in ${EXEFILES}
		${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor

.for bin in ${BINFILES}
		${INSTALL_SCRIPT} ${WRKSRC}/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor

.for man in ${MAN1FILES}
		${INSTALL_MAN} ${WRKSRC}/${man}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor

.for man in ${MAN5FILES}
		${INSTALL_MAN} ${WRKSRC}/${man}.5 ${STAGEDIR}${MAN1PREFIX}/man/man5
.endfor

.include <bsd.port.mk>
