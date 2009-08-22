# ex:ts=8
# Ports collection makefile for:	FSMGenerator
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fsmgenerator
PORTVERSION=	1.0.b.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-cpp/FSMGenerator%201.0b7
DISTNAME=	FSMGenerator${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite State Machine generating software

PLIST_FILES=	bin/fsmgenerator
USE_GMAKE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} \
		${REINPLACE_CMD} -e "s|make$$|${GMAKE}|" \
			-e "s|^CFLAGS[ 	]+=|CFLAGS		+=|" \
			-e "s|/usr/local|${PREFIX}|"

.include <bsd.port.mk>
