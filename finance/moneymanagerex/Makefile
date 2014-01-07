# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmex
PORTVERSION=	0.9.9.0
CATEGORIES=	finance
MASTER_SITES=	http://www.codelathe.com/${PORTNAME}/installer/linux/ \
		SF/moneymanagerex/moneymanagerex/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open-source, easy-to-use personal finance software

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
USE_WX=		2.8+
WX_UNICODE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include			# helps to find boost

post-patch:
	@${REINPLACE_CMD} -e '/man1/s,$$(datadir),${MANPREFIX},' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
