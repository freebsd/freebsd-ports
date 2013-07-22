# New ports collection makefile for:	fondu
# Date created:		2009-11-14
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	fondu
PORTVERSION=	051010
CATEGORIES=	converters
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
DISTNAME=	${PORTNAME}_src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vg@FreeBSD.org
COMMENT=	A series of programs to interconvert between mac fonts

HAS_CONFIGURE=	yes
MAN1=		dfont2res.1 \
		fondu.1 \
		frombin.1 \
		lumper.1 \
		showfond.1 \
		tobin.1 \
		ufond.1

PLIST_FILES=	bin/dfont2res \
		bin/${PORTNAME} \
		bin/frombin \
		bin/lumper \
		bin/setfondname \
		bin/showfond \
		bin/tobin \
		bin/ufond

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${INSTALL_MAN} ${WRKSRC}/dfont2res.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/fondu.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/frombin.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/lumper.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/showfond.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/tobin.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/ufond.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
