# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	make++
PORTVERSION=	2.0
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${PORTNAME:S/+/p/g}/${PORTVERSION}
DISTNAME=	${PORTNAME:S/+/p/g}-${PORTVERSION}

MAINTAINER=	gavin@16degrees.com.au
COMMENT=	Drop-in replacement for GNU make

LICENSE=	ART10 GPLv2+
LICENSE_COMB=	dual

USES=		perl5 tar:txz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man \
		--htmldir=${DOCSDIR}/html
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/${PORTNAME:S/+/p/g}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/+/p/g}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${TOUCH} ${WRKSRC}/.test_done

.include <bsd.port.mk>
