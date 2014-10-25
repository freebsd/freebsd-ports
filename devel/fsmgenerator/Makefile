# Created by: ijliao
# $FreeBSD$

PORTNAME=	fsmgenerator
PORTVERSION=	1.0.b.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-cpp/FSMGenerator%201.0b7
DISTNAME=	FSMGenerator${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite State Machine generating software

BROKEN=		Fails to link
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

USES=		gmake

PLIST_FILES=	bin/fsmgenerator

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} \
		${REINPLACE_CMD} -e "s|make$$|${MAKE_CMD}|" \
			-e "/^RCFLAGS/ s|=|= ${CFLAGS}|" \
			-e "s|/usr/local|${STAGEDIR}${PREFIX}|" \
			-e "s|gcc|${CC}|g"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
