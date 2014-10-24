# Created by: alepulver
# $FreeBSD$

PORTNAME=	masterserver
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	SF/lasange-system/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Masterserver for IdSoftware games (D3, EF, H2, Q2, Q3, QW)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2

post-patch:
	@${REINPLACE_CMD} 's|bindir|DESTDIR)$$(&|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|libdir|DESTDIR)$$(&|' ${WRKSRC}/plugins/Makefile

.include <bsd.port.mk>
