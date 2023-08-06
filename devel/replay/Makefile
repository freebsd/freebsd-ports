PORTNAME=	devel-replay
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/replay/
DISTNAME=	replay-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that helps you fix a build interactively

USES=		tar:bzip2 uidfix
MAKE_ENV=	WITHOUT_MAN=yes

PLIST_FILES=	bin/replay

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.include <bsd.port.mk>
