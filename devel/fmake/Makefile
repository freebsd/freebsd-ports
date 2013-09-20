# $FreeBSD$

PORTNAME=	fmake
PORTVERSION=	r250982
MASTER_SITES=	LOCAL/crees/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/
CATEGORIES=	devel

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Legacy FreeBSD pmake

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

MAKE_ARGS+=	PROG=fmake NO_MAN=yes

NO_STAGE=	yes
do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/make.1 \
			${MAN1PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
