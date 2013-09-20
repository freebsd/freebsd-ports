# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cutecom
PORTVERSION=	0.20.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://cutecom.sourceforge.net/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Graphical serial terminal

RUN_DEPENDS=	lsz:${PORTSDIR}/comms/lrzsz

USE_QT4=	qt3support qmake_build moc_build rcc_build uic_build
USES=		cmake

MAN1=		cutecom.1

NO_STAGE=	yes
.include <bsd.port.mk>
