# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	core
PORTVERSION=	r20091106
CATEGORIES=	devel games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	bennugd-
DISTNAME=	bennugd-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High level open source game development suite, core libs

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS= --bindir="${PREFIX}/libexec"
SUB_FILES=	bgdc bgdi
USE_LDCONFIG=	yes
USE_DOS2UNIX=	*.c *.h

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Segfaults on !i386

WRKSRC=		${WRKDIR}/bennugd/${PORTNAME}

PLIST_FILES=	bin/bgdc bin/bgdi \
		libexec/bgdc libexec/bgdi \
		lib/libbgdrtm.a lib/libbgdrtm.la lib/libbgdrtm.so

post-extract:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bgdi ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/bgdc ${PREFIX}/bin

.include <bsd.port.mk>
